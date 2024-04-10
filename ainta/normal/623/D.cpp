#include<stdio.h>
double P[110], Res;
int w[110];
int n;
bool chk[110];
int main(){
    int i, j, x;
    double Mx, t, S, r;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=1000000;i++){
        Mx=0.0;
        for(j=1;j<=n;j++){
            if(!chk[j])break;
            t = P[j] + (1.0-P[j])*w[j]/100.0;
            if(Mx < t/P[j]){
                Mx = t/P[j];
                x = j;
            }
        }
        if(j!=n+1){
            P[j] = w[j]/100.0;
            chk[j]=true;
            if(i==n){
                S=1.0;
                for(j=1;j<=n;j++)S*=P[j];
                Res += 1-S;
            }
            else Res+=1.0;
            continue;
        }
        P[x] = P[x] + (1.0-P[x])*w[x]/100.0;
        S=1.0;
        for(j=1;j<=n;j++)S*=P[j];
        Res += 1-S;
    }
    printf("%.11f\n",Res+1.0);
}