#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=1e5+5;
int vis[N], d[N], col[N], gdzie[N];
vector<int> E[N];
int n, cent;
void dfs(int v){
    vis[v]=1;
    int czy=1;
    for(int u:E[v]){
        if(!vis[u]){
            dfs(u);
            vis[v]+=vis[u];
            if(vis[u]*2>n)czy=0;
        }
    }
    if((n-vis[v])*2>n)czy=0;
    if(czy)cent=v;
}
void dfs2(int v){
    vis[v]=1;
    for(int u:E[v]){
        if(!vis[u]){
            if(v==cent)col[u]=u;
            else col[u]=col[v];
            d[u]=d[v]+1;
            dfs2(u);
            vis[v]+=vis[u];
        }
    }
    //cout<<v<<" "<<vis[v]<<" "<<d[v]<<" "<<col[v]<<"\n";
}
int main(){

    cin>>n;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1);
    for(int i=0; i<=n; i++){
        vis[i]=0;
    }
    dfs2(cent);
    vector<pair<int, int> > V;
    for(int i=1; i<=n; i++){
        V.push_back({col[i], i});
    }
    sort(V.begin(), V.end(), [](pair<int, int> a, pair<int, int> b){
        if(vis[a.st]==vis[b.st])return a.st<b.st;
        return vis[a.st]<vis[b.st];
    });
    /*for(int i=0; i<n; i++){
        cout<<V[i].st<<" "<<V[i].nd<<"\n";
    }*/
    int ile=0;
    for(int i=n-1; i>=0; i--){
        if(V[i].st!=V[n-1].st){
            ile=n-i-1;
            break;
        }
    }
    //cout<<ile<<" ";
    for(int i=0; i<n; i++){
        gdzie[V[i].nd]=V[(i+ile)%n].nd;
    }
    long long ans=0;
    for(int i=1; i<=n; i++){
        ans+=d[i];
    }
    cout<<ans*2<<"\n";
    for(int i=1; i<=n; i++){
        cout<<gdzie[i]<<" ";
    }
}