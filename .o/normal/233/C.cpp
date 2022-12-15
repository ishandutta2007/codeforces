/* 
 * File:   main.cpp
 * Author: tncks0121
 *
 * Created on 2012 12 28 (),  10:45
 */
#include<stdio.h>
#include<stdlib.h>


int K;
const int N_ = 105;
bool G[N_][N_];
int T, N;

int main() {
    int i, j;
    
    scanf("%d",&K);
    for(N = 1; T < K; ++N){
        for(j = 1; j < N && (T + j - 1) <= K; j++){
            G[N][j] = G[j][N] = 1;
            T += (j - 1);
        }
    }
    
    printf("%d\n",--N);
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++) putchar(G[i][j] ? 49 : 48);
        puts("");
    }
    return 0;
}