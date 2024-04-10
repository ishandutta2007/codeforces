#include<stdio.h>
#include<algorithm>
using namespace std;
int F[210][210], n, m, Res;
bool v[210];
int DFS(int a, int ff){
    v[a]=true;
    if(a == n+n+1){
        Res+=ff;
        return ff;
    }
    int i, b = 1, e = n, t;
    if(F[a][n+n+1]){
        t = DFS(n+n+1,min(ff,F[a][n+n+1]));
        F[a][n+n+1]-=t;
        return t;
    }
    if(1<=a && a<=n)b+=n,e+=n;
    for(i=b;i<=e;i++){
        if(!v[i] &&F[a][i]){
            t = DFS(i, min(ff,F[a][i]));
            if(!t)continue;
            F[a][i]-=t;
            F[i][a]+=t;
            return t;
        }
    }
    return 0;
}
int main(){
    int i, a, b, S = 0, S2 = 0, j;
    scanf("%d%d",&n, &m);
    for(i=1;i<=n;i++){
        scanf("%d",&F[0][i]);
        S += F[0][i];
    }
    for(i=1;i<=n;i++){
        scanf("%d",&F[n + i][n+n+1]);
        S2 += F[n + i][n+n+1];
    }
    if(S!=S2){
        printf("NO\n");
        return 0;
    }
    while(m--){
        scanf("%d%d",&a,&b);
        F[b][n + a] = F[a][n + b] = 999999;
    }
    for(i=1;i<=n;i++)F[i][n+i] = 999999;
    while(DFS(0, 999999)){
        for(i=0;i<=n+n+1;i++)v[i]=false;
    }
    if(Res != S){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",F[n + j][i]);
        }
        printf("\n");
    }
}