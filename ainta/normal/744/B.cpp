#include<stdio.h>
#include<algorithm>
using namespace std;
int n, P[1010], cnt;
int A1[1010][20], A0[1010][20], Res[1010];
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=0;(1<<i) <= n; i++){
        cnt = 0;
        for(j=1;j<=n;j++){
            if((1<<i) & j)P[++cnt] = j;
        }
        printf("%d\n",cnt);
        fflush(stdout);
        for(j=1;j<=cnt;j++)printf("%d ",P[j]);
        printf("\n");
        fflush(stdout);
        for(j=1;j<=n;j++)scanf("%d",&A1[j][i]);
    }
    for(i=0;(1<<i) <= n; i++){
        cnt = 0;
        for(j=1;j<=n;j++){
            if((1<<i) & j)continue;
            P[++cnt] = j;
        }
        printf("%d\n",cnt);
        fflush(stdout);
        for(j=1;j<=cnt;j++)printf("%d ",P[j]);
        printf("\n");
        fflush(stdout);
        for(j=1;j<=n;j++)scanf("%d",&A0[j][i]);
    }
    printf("-1\n");
    fflush(stdout);
    for(i=1;i<=n;i++){
        int Mn = 1999999999;
        for(j=0;(1<<j)<=n;j++){
            if((1<<j) & i){
                Mn = min(Mn, A0[i][j]);
            }
            else{
                Mn = min(Mn, A1[i][j]);
            }
        }
        printf("%d ",Mn);
    }
    printf("\n");
    fflush(stdout);
}