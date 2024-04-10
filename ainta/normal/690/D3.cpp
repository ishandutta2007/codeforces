#include<stdio.h>
#include<algorithm>
using namespace std;
int C,W,H;
long long D[110], w[110][110], Res[110], Mod = 1000003, TP[110][110], TP2[110];
void Do(int t){
    int i,j,k;
    while(t){
        if(t&1){
            for(i=1;i<=W+1;i++)TP2[i]=0;
            for(i=1;i<=W+1;i++){
                for(j=1;j<=W+1;j++){
                    TP2[i] = (TP2[i] + w[i][j]*Res[j])%Mod;
                }
            }
            for(i=1;i<=W+1;i++)Res[i]=TP2[i];
        }
        t>>=1;
        for(i=1;i<=W+1;i++){
            for(j=1;j<=W+1;j++){
                TP[i][j] = 0;
                for(k=1;k<=W+1;k++){
                    TP[i][j]=(TP[i][j]+w[i][k]*w[k][j])%Mod;
                }
            }
        }
        for(i=1;i<=W+1;i++)for(j=1;j<=W+1;j++)w[i][j] = TP[i][j];
    }
}
int main(){
    int i, j;
    scanf("%d%d%d",&C,&W,&H);
    D[1] = 1;
    for(i=2;i<=W+1;i++){
        D[i] = D[i-1]*H%Mod;
    }
    Res[1] = H+1;
    for(i=2;i<=W+1;i++)Res[i] = Res[i-1]*(H+1)%Mod;
    long long tp=1;
    for(i=1;i<=W+1;i++)tp=tp*H%Mod;
    Res[W+1] = (Res[W+1] - tp + Mod)%Mod;
    for(i=1;i<=W+1;i++){
        w[1][i] = D[W+2-i];
    }
    for(i=2;i<=W+1;i++){
        for(j=2;j<=W+1;j++)w[i][j]=w[i-1][j-1];
        w[i][1] = 0;
        for(j=1;j<=W+1;j++)w[i][j] = (w[i][j] + w[i-1][W+1] * w[1][j])%Mod;
    }
    int t = (C-1)/(W+1);
    Do(t);
    printf("%lld\n",Res[(C-1)%(W+1)+1]);
}