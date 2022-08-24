#include<stdio.h>
int i, C[2010000], C2[2010000];
bool pri[2010000];
bool Pos(int a){
    int w[10], cnt = 0, i;
    while (a){
        w[cnt] = a % 10;
        cnt++;
        a /= 10;
    }
    for (i = 0; i < cnt; i++)if (w[i] != w[cnt - i - 1])break;
    return i == cnt;
}
int main(){
    int i, j;
    C2[1] = 1;
    for (i = 2; i <= 2000000; i++){
        C[i] = C[i - 1];
        C2[i] = C2[i - 1];
        if (Pos(i))C2[i]++;
        if (pri[i])continue;
        C[i]++;
        for (j = i + i; j <= 2000000; j += i)pri[j] = true;
    }
    long long p, q;
    scanf("%lld%lld", &p, &q);
    for (i = 2000000; i >= 1; i--){
        if (C2[i] * p >= q * C[i])break;
    }
    printf("%d\n", i);
}