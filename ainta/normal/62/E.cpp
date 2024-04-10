#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m;
long long D[101000][5][32], INF = 1e18;
int W[101000][6], H[101000][6];
int main(){
    int i, j, k, l;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        for(k=0;k<n;k++){
            for(j=0;j<(1<<n);j++){
                D[i][k][j] = INF;
            }
        }
    }
    D[1][n-1][0] = 0;
    for(i=1;i<=m-1;i++){
        for(j=0;j<n;j++)scanf("%d",&W[i][j]);
    }
    for(i=1;i<=m;i++){
        for(j=0;j<n;j++)scanf("%d",&H[i][j]);
    }
    for(i=2;i<=m;i++){
        for(j=0;j<n;j++){
            int pi=i,pj=j-1;
            if(j==0)pi=i-1,pj=n-1;
            for(k=0;k<(1<<n);k++){
                int t1 = k >> (n-1), t2 = k & 1, t3 = (k & 2)>>1;
                for(l=0;l<2;l++){
                    int mask = (k>>1) + (1<<n-1)*l;
                    long long t = D[pi][pj][k];
                    if(l!=t1 && j != 0) t += H[i][j-1];
                    if(l!=t2) t += W[i-1][j];
                    if(l!=t3 && j == n-1) t += H[i][n-1];
                    D[i][j][mask] = min(D[i][j][mask], t);
                }
            }
        }
    }
    printf("%lld\n",D[m][n-1][(1<<n)-1]);
}