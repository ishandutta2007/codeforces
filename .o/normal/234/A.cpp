#include<stdio.h>
#include<stdlib.h>

#define N_ 105
int N;
char D[N_];
int A[N_][2];
int C[N_];

void swap(int &a,int &b){
    int t=a; a=b; b=t;
}

int main(){
    freopen("INPUT.TXT","r",stdin);
    freopen("OUTPUT.TXT","w",stdout);

    int i, j = 0;

    scanf("%d%s",&N,D+1);
    for(i=1; i<=N/2; i++) C[i] = 2*i-1;
    for(i=1; i<=N/2; i++) C[i+N/2] = 2*i;
    for(i=0; i<N/2; i++) A[i][0] = C[i*2+1], A[i][1] = C[i*2+2];
    for(i=0; i<N/2; i++){
        if(D[A[i][1]] == 'L' && D[A[i][0]] == 'R'){
            swap(A[i][0], A[i][1]);
        }
    }

    for(i=0; i<N/2; i++) printf("%d %d\n",A[i][0],A[i][1]);
    return 0;
}