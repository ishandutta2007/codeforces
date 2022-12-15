#include <bits/stdc++.h>
using namespace std;

int c[100001];
vector<int> adj[100001];
int n,m;

bool dfs(int cur,int t) {
    if(c[cur]!=-1) return c[cur]==t;
    c[cur]=t;
    for(auto &it:adj[cur]) {
        if(!dfs(it,t^1)) return false;
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(c,-1,sizeof(c));
    
    int ans=1;
    for(int i=1;i<=n;i++) if(c[i]==-1) {
        ans &= dfs(i,0);
    }

    if(ans) {
        vector<int> a[2];
        for(int i=1;i<=n;i++) a[c[i]].push_back(i);
        for(int i=0;i<2;i++) {
            printf("%lu\n",a[i].size());
            for(auto &it:a[i]) printf("%d ",it);
            puts("");
        }
    } else puts("-1");
    
    return 0;
}