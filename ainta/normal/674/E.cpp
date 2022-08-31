#include<stdio.h>
double D[501000][51], S;
int Q, n = 1, par[501000];
int main(){
    int i, j, ck, x, ch;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&ck,&x);
        if(ck == 1){
            n++;
            D[n][0] = 1.0; par[n] = x;
            for(i=1;i<=50;i++)D[n][i] = 0.0;
            ch = n;
            double tmp = 0.0, tp;
            for(i=1;i<=50 && x;i++){
                tp = D[x][i];
                D[x][i] = 1.0 - (1.0-D[x][i])*(1-0.5*D[ch][i-1])/(1-0.5*tmp);
                tmp = tp;
                ch = x;
                x = par[x];
            }
        }
        else{
            S = 0.0;
            for(i=1;i<=50;i++) S += D[x][i];
            printf("%.10lf\n",S);
        }
    }
}