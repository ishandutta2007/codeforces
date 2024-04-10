/*#include<stdio.h>
int n, w[501000];
int main(){
    int i, be, ed;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++)if(w[i]!=w[1])break;
    be = i;
    for(i=n;i>=1;i--)if(w[i]!=w[n])break;
    ed = i;
    if(be > ed){
        printf("0\n");
        for(i=1;i<=n;i++)printf("%d ",w[i]);
        return 0;
    }
    for(i=1;i<=n;i++){
        if(w[i]
    }
}
*/
#include<stdio.h>
#include<algorithm>
#define INF 999999999
using namespace std;
int D[151][12000];
int n, w[151], K, s;
int main(){
    int i, j, k, ss = 0;
    scanf("%d%d%d",&n,&K,&s);
    s += K*(K+1)/2;
    for(i=n;i>n-K;i--)ss += i;
    s = min(s, ss);
    for(i=1;i<=K;i++){
        for(j=0;j<=ss;j++)D[i][j] = INF;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        for(j=i-1;j>=1;j--){
            if(j>=K)continue;
            for(k=ss;k>=0;k--){
                if(D[j][k]==INF)continue;
                D[j+1][k+i] = min(D[j+1][k+i],D[j][k]+w[i]);
            }
        }
        D[1][i] = min(D[1][i],w[i]);
    }
    int R = INF;
    for(i=1;i<=s;i++)R=min(R,D[K][i]);
    printf("%d\n",R);
}