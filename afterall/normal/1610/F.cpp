#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <string>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <limits.h>
#include <tuple>
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

const int N=2e5+100;
ll a[N];
ll b[N];
set <int> g[N],y[N];
pii jahat[N];
set <pii> s;
ll cnt=0;
void add(ll u,ll v){
  //  cout << "add " << u << ' ' << v << endl;
    cnt++;
    a[cnt]=u;
    b[cnt]=v;
    if (u==v){
        jahat[cnt]={u,v};
        return ;
    }
    s.erase({-(ll)g[u].size(),u});
    s.erase({-(ll)g[v].size(),v});
    g[u].insert(cnt);
    g[v].insert(cnt);
    s.insert({-(ll)g[u].size(),u});
    s.insert({-(ll)g[v].size(),v});
}
void del(ll u,ll v,ll id){
   // cout << " del " << u << " " << v << " " << id << endl;
    s.erase({-(ll)g[u].size(),u});
    s.erase({-(ll)g[v].size(),v});
    g[u].erase(id);
    g[v].erase(id);
    s.insert({-(ll)g[u].size(),u});
    s.insert({-(ll)g[v].size(),v});
}
vector <pair <pii,int> > h;
void Main(ll n){
    s.clear();
    for (int i=1;i<=n;i++){
        s.insert({-(ll)g[i].size(),i});
      //  cout << -(ll)g[i].size() << " " << i << endl;
    }
    while(s.size()){
        ll v=s.begin()->S;
      //  cout << g[v].size() << " VVV " << v << endl;
        if (g[v].size()<=1) break;
        while(g[v].size()>1){
           // cout << " kwjefhjehrbf " << endl;
            auto t=g[v].begin();
            ll id1=*t;
            t++;
            ll id2=*t;
            ll p1=0;
            if (a[id1]+b[id1]==a[id2]+b[id2]){
                jahat[id1]={a[id1]+b[id1]-v,v};
                jahat[id2]={v,a[id2]+b[id2]-v};
                p1=1;
            }
            else add(a[id1]+b[id1]-v,a[id2]+b[id2]-v);
            del(v,a[id1]+b[id1]-v,id1);
            del(v,a[id2]+b[id2]-v,id2);
            if (!p1) h.pb({{id1,id2},cnt});
        }
        
    }
   // cout << "///////////////////////////?" << endl;
    
}
vector <int> G[N];
ll mark[N];
void dfs(ll v){
    for (auto U : G[v]){
        ll u=a[U]+b[U]-v;
        if (!mark[U]){
            mark[U]=1;
            jahat[U]={v,u};
            dfs(u);
        }
    }
}
ll W[N];
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    cnt=m;
    for (int i=1;i<=m;i++){
        ll x;
        
        cin >> a[i] >> b[i] >> x;
        W[a[i]]+=x;
        W[b[i]]+=x;
        if (x==1) {
            g[a[i]].insert(i);
            g[b[i]].insert(i);
        }
        else {
            y[a[i]].insert(i);
            y[b[i]].insert(i);
        }
    }
    for (int i=1;i<=n;i++){
      //  cout << g[i].size() << " erkf " << y[i].size() << endl;
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=W[i]%2;
    }
   
    Main(n);
    for (int i=1;i<=n;i++){
        swap(g[i],y[i]);
    }
    Main(n);
    for (int i=1;i<=n;i++){
        for (auto u : y[i]){
            G[i].pb(u);
        }
        for (auto u : g[i]){
            G[i].pb(u);
        }
    }
    for (int i=1;i<=n;i++){
        if (G[i].size()==1) dfs(i);
    }
    for (int i=1;i<=n;i++){
        dfs(i);
    }
    reverse(h.begin(),h.end());
    for (int i=0;i<h.size();i++){
        ll id1=h[i].F.F;
        ll id2=h[i].F.S;
        ll id=h[i].S;
        if (a[id1]==a[id] || a[id1]==b[id]){
            if (jahat[id].F==a[id1]){
                jahat[id1]={a[id1],b[id1]};
            }
            else jahat[id1]={b[id1],a[id1]};
        }
        else {
            if (jahat[id].F==b[id1]){
                jahat[id1]={b[id1],a[id1]};
            }
            else jahat[id1]={a[id1],b[id1]};
        }
        
        if (a[id2]==a[id] || a[id2]==b[id]){
            if (jahat[id].F==a[id2]){
                jahat[id2]={a[id2],b[id2]};
            }
            else jahat[id2]={b[id2],a[id2]};
        }
        else {
            if (jahat[id].F==b[id2]){
                jahat[id2]={b[id2],a[id2]};
            }
            else jahat[id2]={a[id2],b[id2]};
        }
    }
    cout << ans << endl;
    for (int i=1;i<=m;i++){
        if (jahat[i].F==a[i]) cout << 1 ;
        else cout << 2 ;
    }
    cout << endl;
}