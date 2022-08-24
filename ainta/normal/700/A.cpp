#include<stdio.h>
double T;
int n, v1, v2, L, K;
int main(){
    int i, C;
    scanf("%d%d%d%d%d",&n,&L,&v1,&v2,&K);
    C = (n-1)/K+1;
    double bb = 0, ee = 1e15, LL;
    for(i=0;i<100;i++){
        T = (bb+ee)*0.5;
        LL = (T - T*(v2-v1)/(v1+v2)) * v2 * (C-1) + T * v2;
        if(LL > L){
            ee = T;
        }
        else bb = T;
    }
    printf("%.11lf\n", T + (L - v2*T)  / v1 );
}