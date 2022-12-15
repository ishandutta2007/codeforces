#include<stdio.h>
#include<memory.h>

int N, A, B, C;
int T[5005];

int Table(int n){
    if(n == 0) return 0;
    if(n < 0) return -987654321;
    if(T[n] != -1) return T[n];
    
    int t;
    T[n] = -987654321;
    
    t = Table(n - A);
    if(t + 1 > T[n]) T[n] = t + 1;
    
    t = Table(n - B);
    if(t + 1 > T[n]) T[n] = t + 1;
    
    t = Table(n - C);
    if(t + 1 > T[n]) T[n] = t + 1;
    
    return T[n];
}

int main(){
    scanf("%d%d%d%d", &N, &A, &B, &C);
    memset(T, -1, sizeof(T));
    printf("%d\n",Table(N));
    return 0;
}