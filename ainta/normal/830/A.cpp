#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int D[1010][2010], p, A[1010], B[2010], n, m;
int main(){
    int i, j;
    scanf("%d%d%d",&n,&m,&p);
    for(i=1;i<=n;i++)scanf("%d",&A[i]);
    for(i=1;i<=m;i++)scanf("%d",&B[i]);
    sort(A+1,A+n+1);
    sort(B+1,B+m+1);
    for(i=0;i<=n;i++)for(j=0;j<=m;j++)D[i][j]=2e9;
    D[0][0]=0;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(j!=m)D[i][j+1] = min(D[i][j+1], D[i][j]);
            if(i!=n&&j!=m)D[i+1][j+1] = min(D[i+1][j+1], max(D[i][j], abs(A[i+1]-B[j+1])+abs(B[j+1]-p)));
        }
    }
    printf("%d\n",D[n][m]);
}