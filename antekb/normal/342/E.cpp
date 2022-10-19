#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5, K=20;
int siz[N], ojciec[N], d[K][N], deg[N], fin[N];
int cent, m;
bool red[N], blo[N];
vector<int> E[N], e[N];
void dfs(int v){
    //cout<<"a"<<v<<"\n";
    siz[v]=1;
    bool b=1;
    for(int u:E[v]){
        if(!blo[u] && !siz[u]){
            dfs(u);
            siz[v]+=siz[u];
            if(2*siz[u]>m)  b=0;
        }
    }
    if(2*siz[v]>m && b) cent=v;
    return;
}
void czysc(int v){
    //cout<<"b"<<v<<"\n";
    m++;
    siz[v]=0;
    for(int u:E[v]){
        if(!blo[u] && siz[u])   czysc(u);
    }
}
void licz(int v, int k){
    for(int u:E[v]){
        if(!blo[u] && d[k][u]==0){
            d[k][u]=d[k][v]+1;
            licz(u, k);
        }
    }
}
int tworz(int v, int k){
    //cout<<"c"<<v<<"\n";
    m=0;
    czysc(v);
    dfs(v);
    int sr=cent;
    deg[sr]=k;
    blo[sr]=1;
    licz(sr, k);
    for(int u:E[sr]){
        if(!blo[u]) e[sr].push_back(tworz(u, k+1));
    }
    for(int u:e[sr]){
        ojciec[u]=sr;
    }
    return sr;
}
void add(int v){
    red[v]=1;
    for(int u=v, k=deg[v]; u!=0; u=ojciec[u], k--){
        fin[u]=min(fin[u], d[k][v]);
    }
}
int ans(int v){
    int res=N;
    for(int u=v, k=deg[v]; u!=0; u=ojciec[u], k--) res=min(res, fin[u]+d[k][v]);
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i=1; i<n; i++){
        int u, v;
        cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        siz[i]=1;
        fin[i]=N;
    }
    tworz(1, 0);
    /*for(int i=1; i<=n; i++){
        cout<<ojciec[i]<<"\n";
    }*/
    add(1);
    while(q--){
        int t, v;
        cin>>t>>v;
        if(t==1){
            add(v);
        }
        else{
            cout<<ans(v)<<"\n";
        }
    }
}