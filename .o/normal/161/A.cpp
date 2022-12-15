#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N_ 100000
int X, Y, N, M;
int A[N_+1], B[N_+1];
int res;
int C, R[N_+1][2];

int main(){

    int i, j;

    scanf("%d%d%d%d",&N,&M,&X,&Y);
    for(i=1; i<=N; i++) scanf("%d",A+i);
    for(i=1; i<=M; i++) scanf("%d",B+i);

    j = 1;
    for(i=1; i<=N && j<=M; i++){
        while(j<=M && A[i]-X > B[j]) ++j;
        if(j <= M && B[j] <= A[i]+Y){ ++C; R[C][0] = i; R[C][1] = j; ++j; }
    }

    printf("%d\n",C);
    for(i=1; i<=C; i++) printf("%d %d\n",R[i][0], R[i][1]);

    return 0;
}