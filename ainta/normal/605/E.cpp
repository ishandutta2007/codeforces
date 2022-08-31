#include<stdio.h>
#include<algorithm>
using namespace std;
long double P[1010][1010],D[1010], Mn,S[1010];
double Res;
bool v[1010];
int n;
int main(){
    int i,j,a, x;
    long double c,p,q,tp;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a);
            P[i][j]=a*0.01;
        }
    }
    for(i=1;i<=n;i++){
        D[i]=1e10;
        S[i]=1.0;
    }
    D[n]=0.0;
    while(1){
        Mn = 1e11;x=-1;
        for(i=1;i<=n;i++){
            if(!v[i]&&Mn>D[i]){
                Mn=D[i],x=i;
            }
        }
        if(x==1){
            Res = D[x];
            printf("%.11lf\n",Res);
            return 0;
        }
        v[x]=true;
        for(i=1;i<=n;i++){
            if(!v[i]){
                p = P[i][x];
                q = S[i];
                if(p<0.005)continue;
                if(q>0.995){
                    D[i] = 1.0/p + D[x];
                    S[i] *=(1.0-p);
                    continue;
                }
                tp = p*q*1.0/(1.0-(1.0-p)*q);
                D[i] = (1.0-tp)*(D[i]) +tp*(D[x]);
                S[i] *=(1.0-p);
            }
        }
    }
}