#include<stdio.h>
#define SZ 131072
int n;
int IT[262144][60];
void UDT(int a){
    while (a != 1){
        a >>= 1;
        for (int x = 0; x < 60; x++){
            IT[a][x] = IT[a * 2][x] + IT[a * 2 + 1][(x + IT[a * 2][x]) % 60];
        }
    }
}
void Do(int a, int b){
    a += SZ;
    int i;
    for (i = 0; i < 60; i++){
        if (i%b == 0)IT[a][i] = 2;
        else IT[a][i] = 1;
    }
    UDT(a);
}
int P[20];
int Sum(int a, int b){
    a += SZ, b += SZ;
    int cnt = 0, res = 0, i;
    while (a <= b){
        if (a & 1){
            res += IT[a][res%60];
        }
        if (!(b & 1))P[cnt++] = b;
        a = (a + 1) >> 1, b = (b - 1) >> 1;
    }
    for (i = cnt - 1; i >= 0; i--){
        res += IT[P[i]][res%60];
    }
    return res;
}
int main(){
    int i, Q, a, b;
    char p[2];
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &a);
        Do(i, a);
    }
    scanf("%d", &Q);
    while (Q--){
        scanf("%s", p);
        scanf("%d%d", &a, &b);
        if (p[0] == 'C'){
            Do(a, b);
        }
        else printf("%d\n", Sum(a, b - 1));
    }
}