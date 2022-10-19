#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5, K=18;
int vis[N], d[N], anc[K][N], dol[N], d2[N];
vector<int> E[N];
int l, n, a, b, root;
void dfs1(int v){
    for(int u:E[v]){
        if(!vis[u]){
            vis[u]=vis[v]+1;
            dfs1(u);
            d[v]=max(d[v], d[u]+1);
        }
    }
}
void dfs2(int v, int k){
    vis[v]=1;
    int cnt=0, m1=-N, m2=-N;
    for(int u:E[v]){
        if(vis[u])continue;
        if(d[u]>=l-1)cnt++;
        if(d[u]>m1){
            m2=m1;
            m1=d[u];
        }
        else if(d[u]>m2)m2=d[u];
    }
    if(k>=l)cnt++;
    if(cnt>=3){
        root=v;
    }
    //cout<<"x"<<v<<" "<<d[v]<<" "<<m1<<" "<<m2<<" "<<cnt<<" "<<k<<"\n";
    for(int u:E[v]){
        if(!vis[u]){
            dfs2(u, max(k+1, (m1==d[u]) ? m2+2 : m1+2));
        }
    }
}
void dfs3(int v){
    vis[v]=1;
    d[v]=0;
    dol[v]=v;
    for(int u:E[v]){
        if(!vis[u]){
            anc[0][u]=v;
            d2[u]=d2[v]+1;
            dfs3(u);
            if(d[u]+1>d[v]){
                dol[v]=dol[u];
                d[v]=d[u]+1;
            }
        }
    }
}
int eval(int v, int k){
    for(int i=K-1; i>=0; i--){
        if((1<<i)<=k){
            k-=(1<<i);
            v=anc[i][v];
        }
    }
    return v;
}
bool solve(){
    cin>>n>>a>>b;
    for(int i=1; i<=n; i++){
        vis[i]=0;
        dol[i]=0;
        d[i]=0;
        d2[i]=0;
        anc[0][i]=0;
        E[i].clear();
    }
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vis[a]=1;
    dfs1(a);
    l=vis[b]-1;
    //cout<<l<<"\n";
    for(int i=1; i<=n; i++){
        vis[i]=0;
    }
    root=0;
    dfs2(a, 0);
    for(int i=1; i<=n; i++){
        vis[i]=0;
    }
    if(!root){
        return false;
    }
    //cout<<"a"<<root<<"\n";
    d2[root]=0;
    dfs3(root);
    for(int i=1; i<K; i++){
        for(int j=1; j<=n; j++){
            anc[i][j]=anc[i-1][anc[i-1][j]];
        }
    }
    if(b==dol[b])swap(a, b);
    if(abs(d2[a]-d2[b])==l)return 1;
    while(true){
        //cout<<a<<"a"<<b<<"\n";
        //if(a==dol[a] && b==dol[b])return 0;
        if(!vis[dol[a]])return 0;
        b=eval(b, d[a]);
        a=dol[a];
        vis[a]=0;
        if(d2[a]-d2[b]>=l || b==0)return 1;
        swap(a, b);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }
}