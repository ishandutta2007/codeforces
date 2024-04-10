#include <bits/stdc++.h>
using namespace std;

int n,m,cnt[200001];
vector<int> adj[200001];

long long ans=0;
int dfs(int cur,int p) {
    for(auto &it:adj[cur]) if(it!=p) cnt[cur] += dfs(it,cur);
    ans += min(cnt[cur], 2*m-cnt[cur]);
    return cnt[cur];
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,v;i<2*m;i++) {
        scanf("%d",&v);
        cnt[v]++;
    }
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    printf("%lld\n",ans);
    
    return 0;
}