#include <bits/stdc++.h>
using namespace std;
int adj[401][401],n,m;

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }
    if(adj[1][n]) {
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) if(i!=j) adj[i][j]^=1;
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        if(adj[i][k] && adj[k][j] && (adj[i][j]==0 || adj[i][j] > adj[i][k]+adj[k][j])) {
            adj[i][j] = adj[i][k] + adj[k][j];
        }
    }
    if(!adj[1][n]) adj[1][n]=-1;
    printf("%d\n",adj[1][n]);
    return 0;
}