#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE_OF_INPUTED_STRING 1000000
#define SIZE_OF_ALPHABET 26

//func prototypes
void dencryptFunc(char* enteredString, char* codeVidgener);
void encryptFunc(char* enteredString, char* codeVidgener);
int validateFuncArgs(int argc, char** argv);
char* gotString(char* msgForUser);


int main(int argc, char** argv) {
    
    if (validateFuncArgs(argc, argv)){
        return 0;
    }
    char* enteredString = gotString("Pls enter string which you want to encrypt/decrypt: ");
    char* codeVidgener = gotString("Pls enter Vidgener code (text): ");
    
    if (!strcmp (argv[1], "-e")){
        encryptFunc(enteredString, codeVidgener);
    }
    
    if (!strcmp (argv[1], "-d")){
        dencryptFunc(enteredString, codeVidgener);
    }
    
    //if returned string isn't empty
    if (enteredString[0] != 0){
        printf("Result: ");
        puts(enteredString);
    }
    
    free(enteredString);
    free(codeVidgener);
    return 0;
}

//validate arguments
int validateFuncArgs(int argc, char** argv ){
    
    //check if user enters lower than one symbol (arguments)
    if (argc <= 1){
        printf("ATTENTION! For correct running use arguments: -e: for encryption; -d: for decription");
        return 1;
    }
    
    //check if user enters correct arguments
    if (!strcmp (argv[1], "-e") || !strcmp (argv[1], "-d")){
        return 0;
    }
    else {
        printf("ATTENTION! For correct running use arguments: -e: for encryption; -d: for decription");
        return 1;
    }
}

//eccrypt function
void encryptFunc(char* enteredString, char* codeVidgener){
    int i,j;
    int sizeOfString = strlen(enteredString);
    for(i = 0, j = 0; i < strlen(enteredString); i++, j++){
        //if end of code, reset and start from the first symbol
        if (j == strlen(codeVidgener)){
            j = 0;
        }
        if (isalpha(enteredString[i])){
            enteredString[i] = (tolower(enteredString[i]) + tolower(codeVidgener[j]) - 2 * 'a');
            enteredString[i] = enteredString[i] % SIZE_OF_ALPHABET + 'a';
        }
    }
}

//decrypt function
void dencryptFunc(char* enteredString, char* codeVidgener){
    int i, j;
    int sizeOfString = strlen(enteredString);
    //if end of code, reset and start from the first symbol
    for(i = 0, j = 0; i < strlen(enteredString); i++, j++){
        if (j == strlen(codeVidgener)){
            j = 0;
        }
        if (isalpha(enteredString[i])){
            enteredString[i] = (tolower(enteredString[i]) - tolower(codeVidgener[j]) + SIZE_OF_ALPHABET);
            enteredString[i] = enteredString[i] % SIZE_OF_ALPHABET + 'a';
        }
    }
}

// get string function
char* gotString(char* invitationMsg){
    
    printf("%s", invitationMsg);
    char* inputerdString;
    inputerdString = (char*) malloc(SIZE_OF_INPUTED_STRING * sizeof(char));
    gets(inputerdString);
    
    if (inputerdString[0] == 0){
        printf("Error! Empty string\n");
    }
    
    for (int i = 0; i < strlen(inputerdString); i++){
        if (!isalpha(inputerdString[i])){
            printf("ERROR! STRING CAN'T CONTAIN A DIGIT\n");
            return 0;
        }
    }
    fpurge(stdin);
    return inputerdString;
}



