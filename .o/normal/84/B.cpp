#include<stdio.h>

int N;
int D;
long long res, C;

int main(){
    scanf("%d",&N); while(N--){
        int d; scanf("%d",&d);
        if(D != d){
            res += C * (C+1) / 2;
            D = d; C = 1;
        }else ++C;
    }
    if(C > 0) res += C * (C+1) / 2;
    printf("%I64d\n",res);
    return 0;
}