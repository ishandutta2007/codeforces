#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=4e5+100,M=20;
vector <int> g[N];
ll par[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
ll dis[N];
ll mrg(ll u,ll v){
    ll u1=getpar(u),v1=getpar(v);
    par[u1]=v1;
}
ll pd[N][M],hi[N];
ll dfs(ll v,ll p){
    pd[v][0]=p;
    hi[v]=hi[p]+1;
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v);
    }
}
ll get(ll v,ll h){
    if (h<=0) return v;
    for (int i=M-1;i>-1;i--){
        if ((h & (1<<i))) v=pd[v][i];
    }
    return v;
}
ll lca(ll u,ll v){
    if (hi[u]<hi[v]) swap(u,v);
    u=get(u,hi[u]-hi[v]);
    if (u==v) return u;
    for (int i=M-1;i>-1;i--){
        if (pd[u][i]!=pd[v][i]){
            u=pd[u][i];
            v=pd[v][i];
        }
    }
    return pd[v][0];
}
ll vis[N];
int32_t main(){
    sync;
    memset(dis,31,sizeof dis);
    ll n,k,t;
    cin >> n >> k >> t;
    ll cnt=n+1;
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(cnt);
        g[cnt].pb(u);
        g[cnt].pb(v);
        g[v].pb(cnt);
      //  if (v+u==10){
     //       cout << cnt << " fjnrf " << endl;
       // }
        cnt++;
    }
    for (int i=1;i<=t;i++){
        ll v;
        cin >> v;
        dis[v]=0;
    }
    queue <int> q;
    for (int i=1;i<cnt;i++){
        par[i]=i;
        if (dis[i]==0) q.push(i);
    }
    while(q.size()){
        ll v=q.front();
        q.pop();
        if (vis[v]) continue;
        if (dis[v]==k) continue;
        for (auto u : g[v]){
            mrg(u,v);
            if (dis[u]>dis[v]+1){
                dis[u]=dis[v]+1;
                q.push(u);
            }
        }
    }
   // for (int i=1;i<cnt;i++){
  //      cout << getpar(i) << " ";
//    }
    //cout << endl;
    dfs(1,1);
    for (int i=1;i<M;i++){
        for (int j=1;j<cnt;j++){
            pd[j][i]=pd[pd[j][i-1]][i-1];
        }
    }
    ll qq;
    cin >> qq;
    while(qq--){
        ll u,v;
        cin >> u >> v;
        ll f=lca(u,v);
        if (hi[u]-hi[f]+hi[v]-hi[f]<=2*k){
            cout << "YES" << endl;
            continue;
        }
        if (hi[u]-hi[f]>=k){
            u=get(u,k);
        }
        else{
            ll z=hi[u]-hi[f];
            z=k-z;
            z=hi[v]-hi[f]-z;
            u=get(v,z);
        }
        if (hi[v]-hi[f]>=k){
            v=get(v,k);
        }
        else{
            ll z=hi[v]-hi[f];
            z=k-z;
            z=hi[u]-hi[f]-z;
            v=get(u,z);
        }
        if (getpar(u)==getpar(v)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
 //   cout << get(1,k) << " " << getpar(get(1,k)) << endl;
}