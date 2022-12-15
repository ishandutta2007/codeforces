#include<stdio.h>

#define S 1005
typedef long long lld;
int N, M;
int A[S], B[S];
lld res;
char D[S][S];

int main(){
    int i, j;

    scanf("%d%d",&N,&M);
    for(i=0; i<N; i++){
        scanf("%s",D[i]);
        for(j=0; j<M; j++){
            if(D[i][j] == '*') A[i]++, B[j]++;
        }
    }

    for(i=0; i<N; i++) for(j=0; j<M; j++) if(D[i][j] == '*'){
        res += (lld)(A[i]-1)*(B[j]-1);
    }

    printf("%I64d\n",res);
    return 0;
}