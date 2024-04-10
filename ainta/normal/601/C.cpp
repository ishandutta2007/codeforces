#include<stdio.h>
int n, m, w[110];
double P[111000], P2[111000], Res, SS;
int main(){
    int i, j, k, S = 0;
    scanf("%d%d",&n,&m);
    if(m==1){
        printf("%.10lf\n",1.0);
        return 0;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        S += w[i];
    }
    P[0]=1.0;
    for(i=1;i<=n;i++){
        SS = 0.0;
        for(j=0;j<=m*(i-1);j++){
            SS += P[j];
            if(j>=m)SS -= P[j-m];
            P2[j+1] = SS;
            if(j+1 >= w[i]) P2[j+1] -= P[j+1-w[i]];
        }
        for(j=m*(i-1)+2;j<=m*i;j++){
            if(j>m)SS-= P[j-m-1];
            P2[j] = SS;
            if(j >= w[i]) P2[j] -= P[j-w[i]];
        }
        for(j=0;j<=m*i;j++){
            P[j] = P2[j]/(m-1);
            P2[j] = 0.0;
        }
    }
    for(i=0;i<S;i++)Res += (m-1)*P[i];
    printf("%.10lf\n",Res+1.0);
}