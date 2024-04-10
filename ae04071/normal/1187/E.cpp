#include <bits/stdc++.h>
using namespace std;

int n,cnt[200001];
long long val[200001];
vector<int> adj[200001];

long long ans=0;
void dfs(int cur,int p) {
    for(auto &it:adj[cur]) if(it!=p) {
        dfs(it,cur);
        val[cur] += val[it]+cnt[it];
        cnt[cur] += cnt[it];
    }
    cnt[cur]++; val[cur]++;
}
void get(int cur,int p,int c,long long v) {
    ans = max(ans, v+val[cur]);

    for(auto &it:adj[cur]) if(it!=p) {
        get(it,cur,c+cnt[cur]-cnt[it], v+val[cur]-(val[it]+cnt[it]) + (c+cnt[cur]-cnt[it]));
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    get(1,0,0,0);
    printf("%lld\n",ans);
    return 0;
}