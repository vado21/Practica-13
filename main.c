/**Eduardo Andre Martinez Romero A00819264 **/
/**David Martinez A00820087 **/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

///Creacion de la instancia
HINSTANCE hCodigoDll;
int lResult;

///Apuntadores a las funciones
typedef int (THE_FUNCTION_1)(char*,int);
THE_FUNCTION_1* ptrHex=0;

typedef int (THE_FUNCTION_2)(char *,int);
THE_FUNCTION_2* ptrBinary=0;

typedef int (THE_FUNCTION_3)(char *,int);
THE_FUNCTION_3* ptrOct=0;

typedef int (THE_FUNCTION_4)(int *);
THE_FUNCTION_4* ptrDivTwo=0;

typedef int (THE_FUNCTION_5)(int *);
THE_FUNCTION_5* ptrMultTwo=0;

///Despliege del Menu
void menu(){
    printf("QUE INTRODUCIRAS?\n");
    printf("1. Numero hexadecimal\n");
    printf("2. Numero Binario\n");
    printf("3. Numero OCTGONAL\n");
    printf("4. Dividire un numero entre dos\n");
    printf("5. Multiplicar un numero por dos\n");
}

void main()
{
    ///Llamando a la libreria "Libreria.dll"
    if (hCodigoDll = LoadLibrary("Libreria.dll")) {

    while(1){
    menu();
    int iMenu;
	int iNum;
        scanf("%d",&iMenu);
        printf("\n");
        if(iMenu == 1){
            printf("Introduce el numero:");
            char string[256];
            scanf("%s",string);
                if (ptrHex=(THE_FUNCTION_1*)GetProcAddress(hCodigoDll ,"asciiHexToInt")) {
                    lResult=(*ptrHex)(&string,strlen(string));
                    if(lResult == -1){
                        printf("No es un numero hexadecimal\n");
                    }
                    else{
                        printf("Su numero en decimal es: %d \n",lResult);
                    }
                }
                else
                    printf("ERROR: Routine not found!\n");

        }
        else if(iMenu == 2){
            char string[256];
            printf("Introduce el numero\n");
            scanf("%s",string);
            if (ptrBinary=(THE_FUNCTION_2*)GetProcAddress(hCodigoDll ,"asciiBinaryToInt")) {
                    lResult=(*ptrBinary)(&string,strlen(string));
                    if(lResult == -1){
                        printf("No es un numero hexadecimal\n");
                    }
                    else{
                        printf("Su numero en decimal es: %d \n",lResult);
                    }
                }
                else
                    printf("ERROR: Routine not found!\n");

        }
        else if(iMenu == 3){
            char string[256];
            printf("Introduce el numero\n");
            scanf("%s",string);
	         if (ptrOct=(THE_FUNCTION_3*)GetProcAddress(hCodigoDll ,"asciiOCTToInt")) {
                    lResult=(*ptrOct)(&string,strlen(string));
                    if(lResult == -1){
                        printf("No es un numero hexadecimal\n");
                    }
                    else{
                        printf("Su numero en decimal es: %d \n",lResult);
                    }

                }
                else
                    printf("ERROR: Routine not found!\n");
        }
        else if(iMenu == 4){
            printf("Introduce el numero\n");
            scanf("%d",&iNum);
            if (ptrDivTwo=(THE_FUNCTION_4*)GetProcAddress(hCodigoDll ,"divideByTwo")) {
                    lResult=(*ptrDivTwo)(&iNum);
                    printf("Su numero dividido en 2 es: %d \n",lResult);
                }
                else
                    printf("ERROR: Routine not found!\n");
            }
        else if(iMenu == 5){
            printf("Introduce el numero\n");
            scanf("%d",&iNum);
            if (ptrMultTwo=(THE_FUNCTION_5*)GetProcAddress(hCodigoDll ,"multiplyByTwo")) {
                    lResult=(*ptrMultTwo)(&iNum);
                    printf("Su numero es multiplicado por 2 es: %d \n",lResult);
                }
                else
                    printf("ERROR: Routine not found!\n");
            }

    }
    }
    else
        printf("ERROR: Library not found!\n");

    FreeLibrary(hCodigoDll);

    getchar();

    return 0;
}
