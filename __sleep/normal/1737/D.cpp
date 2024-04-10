#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
using ll=long long;
const int N=503,P=1000000007;
int n,m,dis[N][N];
vector<int> nxt[N];
struct Edge{
    int u,v,w;
} e[N*N];
void dij(int s){
    dis[s][s]=0;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,s});
    vector<bool> vis(n,false);
    while(!pq.empty()){
        auto now=pq.top(); pq.pop();
        auto d=now.first;
        auto u=now.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:nxt[u]){
            if(dis[s][v]<=dis[s][u]+1) continue;
            dis[s][v]=dis[s][u]+1;
            pq.push({-dis[s][v],v});
        }
    }
}
void work(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        nxt[i].clear();
        for(int j=1;j<=n;j++)
            dis[i][j]=1e9;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[i]={u,v,w};
        nxt[u].push_back(v);
        nxt[v].push_back(u);    
    }
    for(int i=1;i<=n;i++)
        dij(i);
    ll ans=1e18;
    for(int i=0;i<m;i++){
        auto u=e[i].u,v=e[i].v,w=e[i].w;
        ans=min(ans,1ll*w*(dis[1][u]+dis[v][n]+1));
        ans=min(ans,1ll*w*(dis[n][u]+dis[v][1]+1));
        for(int j=1;j<=n;j++){
            ans=min(ans,
                1ll*w*(dis[u][j]+dis[j][1]+dis[j][n]+2));
            ans=min(ans,
                1ll*w*(dis[v][j]+dis[j][1]+dis[j][n]+2));
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) work();
    return 0;
}