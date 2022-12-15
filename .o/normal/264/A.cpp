#include <stdio.h>
#include <string.h>

const int N_ = 1000005;

char D[N_];
int N;

int main(){
    scanf("%s", D + 1);
    N = strlen(D + 1);
    
    for(int i = 1; i <= N; i++){
        if(D[i] == 'r') printf("%d\n", i);
    }
    for(int i = N; i > 0; i--){
        if(D[i] == 'l') printf("%d\n", i);
    }
    return 0;
}