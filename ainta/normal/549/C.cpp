#include<stdio.h>
int K, n, A, B, R;
int main(){
    int i, a;
    scanf("%d%d", &n, &K);
    for (i = 1; i <= n; i++){
        scanf("%d", &a);
        if (a & 1)A++;
        else B++;
    }
    if (n == K)R = (A & 1);
    else if (n == K + 1){
        if (A == 0)R = 0;
        else if (B == 0){
            if (K % 2 == 0)R = 0;
            else R = 1;
        }
        else R = 1;
    }
    else{
        if (A >= B + K){
            if (K % 2 == 0)R = 0;
            else R = 1;
        }
        else if (B >= A + K)R = 0;
        else{
            if (n % 2 != K % 2)R = 1;
            else R = 0;
        }
    }
    if (R)printf("Stannis\n");
    else printf("Daenerys\n");
}