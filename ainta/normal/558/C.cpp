#include<stdio.h>
int w[151000], n, P[151000], D[151000], tD[151000];
int Q[400], t, C[400];
void Do(int a, int c){
    while(a<=131072){
        t++;
        Q[t] = a;
        C[t] = c;
        c++;
        a*=2;
    }
}
int main(){
    int i, x, c, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    for(i=1;i<=n;i++){
        x = w[i];
        t = 0;
        c = 0;
        while(x){
            Do(x,c);
            x>>=1;
            c++;
        }
        for(j=1;j<=t;j++){
            x = Q[j];
            if(P[x] < i-1)continue;
            if(P[x] == i-1){
                P[x] = i;
                tD[x] = D[x] + C[j];
            }
            else{
                if(tD[x] > D[x] + C[j])tD[x] = D[x]+C[j];
            }
        }
        for(j=1;j<=t;j++)D[Q[j]]=tD[Q[j]];
    }
    int Res = 999999999;
    for(i=1;i<=131072;i++){
        if(P[i] == n && D[i] < Res){
            Res = D[i];
        }
    }
    printf("%d\n",Res);
}