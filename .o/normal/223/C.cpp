#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

#define N_ 2005
const int MOD = 1000000007;
typedef long long lld;
int N, K;
int A[N_];

struct Matrix{
    int *M;
    Matrix(){ M = (int*)calloc(N+1, sizeof(int)); }
    Matrix operator* (const Matrix &t){
        Matrix ret;
        for(int i=1; i<=N; i++) for(int j=1; j<=i; j++){
            int n = ((lld)M[j] * (lld)t.M[i+1-j]) % MOD;
            ret.M[i] += n; ret.M[i] %= MOD;
        }
        return ret;
    }
};

Matrix res; bool res_ck;

int main(){
    int i, j;

    scanf("%d%d",&N,&K);
    for(i=1; i<=N; i++) scanf("%d",A+i);

    if(K == 0){
        for(i=1; i<=N; i++) printf("%d ",A[i]);
        return 0;
    }
        
    Matrix v;
    for(i=1; i<=N; i++) v.M[i] = 1;
    while(K > 0){
        if(K & 1){
            if(res_ck) res = res * v;
            else res = v, res_ck = true;
        }
        v = v * v; K >>= 1;
    }

    for(i=1; i<=N; i++){
        lld sum = 0;
        for(j=1; j<=i; j++){
            sum = (sum + (lld)A[j] * (lld)res.M[i-j+1]) % MOD;
        }
        printf("%I64d ",sum);
    }
    return 0;
}