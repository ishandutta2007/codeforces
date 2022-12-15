#include <stdio.h>

const int SZ = 100005;

int N, M;
int A[SZ], G;
long long res;

int D[SZ*20], DN;

int gcd (int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int i, j;
    
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i++) {
        scanf("%d", A + i);
        --A[i];
    }
    
    G = A[1];
    while((G & 1) == 0) G >>= 1;
    for(i = 2; i <= N; i++) G = gcd(G, A[i]);
    
    for(i = 1; i * i <= G; i++) {
        if(G % i) continue;
        D[++DN] = i;
        if(i * i != G) D[++DN] = G / i;
    }
    
    for(i = 1; i <= DN; i++){
        if(((long long)D[i] << 1) < M) D[++DN] = D[i] << 1;
    }
    
    for(i = 1; i <= DN; i++){
        res += (D[i] < M) ? (M - D[i]) : 0;
    }
    
    printf("%lld\n", res);
    return 0;
}