#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;

int u[200001],v[200001],w[200001],n;
int pa[200001],sz[200001];

int find(int cur) {
    return cur==pa[cur] ? cur : pa[cur] = find(pa[cur]);
}
void merge(int u,int v) {
    u=find(u); v=find(v);
    pa[v]=u;
    sz[u]+=sz[v];
}
vector<int> adj[200001];

int main() {
    scanf("%d",&n);
    
    for(int i=1;i<n;i++) {
        scanf("%d%d%d",u+i,v+i,w+i);
        adj[u[i]].push_back(i);
        adj[v[i]].push_back(i);
    }
    for(int i=1;i<n;i++) pa[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(),adj[i].end(), [&](const int &a,const int &b){
            return w[a]<w[b];
        });
        for(int j=1;j<sz(adj[i]);j++) {
            if(w[adj[i][j]] == w[adj[i][j-1]]) merge(adj[i][j],adj[i][j-1]);
        }
    }
    
    long long ans=0;
    for(int i=1;i<=n;i++) {
        int f[2]={0,};
        for(int j=1;j<sz(adj[i]);j++) {
            if(w[adj[i][j-1]]!=w[adj[i][j]]) {
                ans += 1ll*sz[find(adj[i][j-1])]*sz[find(adj[i][j])];
            }
        }
    }
    for(int i=1;i<n;i++) if(find(i)==i) {
        ans += 1ll*sz[i]*(sz[i]+1);
    }
    
    printf("%lld\n",ans);
    
    return 0;
}