#include<stdio.h>
#include<algorithm>
using namespace std;
int D[2][110][11000], ck;
int n,A[110],B[110],S;
int main(){
    int i,j,k,SS;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        S+=A[i];
    }
    for(i=1;i<=n;i++)scanf("%d",&B[i]);
    SS=0;
    for(i=1;i<=n;i++){
        ck = !ck;
        for(j=0;j<i;j++){
            for(k=0;k<=SS;k++){
                if(!D[!ck][j][k] && (j||k))continue;
                D[ck][j][k] = max(D[ck][j][k],D[!ck][j][k]);
                D[ck][j+1][k+B[i]] = max(D[ck][j+1][k+B[i]], D[!ck][j][k] + A[i]);
            }
        }
        SS += B[i];
    }
    for(i=1;i<=n;i++){
        for(j=S;j<=SS;j++){
            if(D[ck][i][j])break;
        }
        if(j!=SS+1){
            printf("%d ",i);
            int MM = 0;
            for(j=S;j<=SS;j++){
                MM = max(MM,D[ck][i][j]);
            }
            printf("%d\n",S-MM);
            return 0;
        }
    }
}