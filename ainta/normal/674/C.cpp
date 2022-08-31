#include<stdio.h>
int n, K, w[201000];
double D[51][201000], S1[201000], S2[201000], SS;
void DP(int dep, int b, int e, int s, int l, double g){
    if(l>=e)l=e-1;
    int i;
    int m = (b+e)>>1, x;
    double Mn, gg = g;
    for(i=b;i<=m;i++){
        g += (S1[i]-S1[s])/w[i];
    }
    Mn = D[dep-1][s] + g, x = s;
    for(i=s+1;i<=l&&i<m;i++){
        g -= (S2[m]-S2[i-1])*w[i];
        if(Mn >D[dep-1][i] + g) Mn = D[dep-1][i] + g, x = i;
    }
    D[dep][m] = Mn;
    if(b==e)return;
    if(b<m)DP(dep, b, m-1, s, x, gg);
    if(m<e)DP(dep, m+1, e, x, l, Mn - D[dep-1][x]);
}
int main(){
    int i, pv, j;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        S1[i] = S1[i-1] + w[i];
        S2[i] = S2[i-1] + 1.0/w[i];
    }
    for(i=1;i<=n;i++){
        D[1][i] = D[1][i-1] + S1[i]/w[i];
    }
    for(i=2;i<=K;i++){
        DP(i,i,n,i-1,n-1,0.0);
    }
    printf("%.11lf\n",D[K][n]);
}