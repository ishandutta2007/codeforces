#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n,m,vis[5001],ans[5001];
int adj[5001][5001];

bool dfs(int cur) {
    if(vis[cur]==1) return true;
    else if(vis[cur]==2) return false;
    vis[cur] = 1;
    for(int j=1;j<=n;j++) if(adj[cur][j]) if(dfs(j)) return true;
    vis[cur]=2;
    return false;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++) {
        scanf("%d%d",&u,&v);
        adj[u][v] = i+1;
    }
    
    for(int i=1;i<=n;i++) if(!vis[i]) if(dfs(i)) {
        puts("2");
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(adj[i][j]) {
            if(i<j) ans[adj[i][j]] = 1;
            else ans[adj[i][j]] = 2;
        }
        for(int i=1;i<=m;i++) printf("%d ",ans[i]);
        return 0;
    }
    puts("1");
    for(int i=0;i<m;i++) printf("1 ");
    
    return 0;
}