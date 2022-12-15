/* 
 * File:   main.cpp
 * Author: tncks0121
 *
 * Created on 2012 12 28 (),  10:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N_ = 2005;

int N;
char D[N_];

bool P[N_][N_];
int TableL[N_], TableR[N_];

typedef long long lld;
lld res;

int main() {
    int i, j;
    
    scanf("%s", D + 1);
    N = strlen(D + 1);
    
    for(i = 1; i <= N; i++){
        P[i][i] = true;
        if(D[i] == D[i + 1]) P[i][i + 1] = true;
    }
    
    for(int l = 3; l <= N; l++){
        for(i = 1, j = l; j <= N; i++, j++){
            if(D[i] == D[j]) P[i][j] = P[i + 1][j - 1];
        }
    }
  
    // TableL[i] = D[1..i] 1   
    // TableR[i] = D[i..N] 1   
    
    TableL[1] = 1;
    for(i = 2; i <= N; i++){
        for(j = 1; j <= i; j++) if(P[j][i]) ++TableL[i];
    }
    
    TableR[N] = 1;
    for(i = N - 1; i > 0; i--){
        for(j = i; j <= N; j++) if(P[i][j]) ++TableR[i];
    }
    
    for(i = 1; i < N; i++){
        for(j = i + 1; j <= N; j++){
            res += (lld) TableL[i] * TableR[j];
        }
    }
    
    printf("%lld\n", res);
    
    return 0;
}