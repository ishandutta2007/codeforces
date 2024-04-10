#include <bits/stdc++.h>
using namespace std;

int n,m,pa[300001],sz[300001],ans[300001];
vector<int> adj[300001];

void dfs(int cur) {
    sz[cur] = 1;

    int mx=0,mi=0;
    for(auto &it:adj[cur]) {
        dfs(it);
        sz[cur] += sz[it];
        
        if(mx < sz[it]) {
            mx = sz[it];
            mi = it;
        }
    }
    if(mx==0) {
        ans[cur] = cur;
    } else {
        ans[cur] = ans[mi];
        while(sz[ans[cur]] <= sz[cur]/2)  ans[cur] = pa[ans[cur]];
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++) {
        scanf("%d",pa+i);
        adj[pa[i]].push_back(i);
    }

    dfs(1);
    
    while(m--) {
        int v;
        scanf("%d",&v);
        printf("%d\n",ans[v]);
    }
    
    return 0;
}