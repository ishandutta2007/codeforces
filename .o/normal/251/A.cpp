#include<stdio.h>

int N, D;
long long res;
long long X[100005];

long long f(long long v){
    return v*(v-1)/2;
    // * * * *
    // (4-2) + (4-3)
}

int main(){
    int i, j;
    
    scanf("%d%d",&N,&D);
    for(i = 1, j = 1; i <= N; i++){
        int v; scanf("%d", &v); X[i] = v;
        while(X[i] - X[j] > D && j < i){
            ++j;
        }
        res += f(i - j);
    }
    
    printf("%I64d\n",res);
    return 0;
}