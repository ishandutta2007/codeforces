// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
ll dsu[N], sz[N];
ll _f(ll v){
    return dsu[v]==v?v:dsu[v]=_f(dsu[v]);
}
void _u(ll a, ll b){
    a=_f(a), b=_f(b);
    if(a==b) return;
    dsu[b]=a;
    sz[a]+=sz[b];
}
vector<ll> res;
stack<ll> later;
vector<pll> d[N];
pll pp[N];
ll x, a[N];
bool was[N];
ll tin[N], tout[N], timer=0;
void dfs(ll v, ll p=-1, ll ppp=-1){
    pp[v]={p, ppp};
    was[v]=1;
    tin[v]=++timer;
    for(auto i : d[v]){
        if(was[i.x]) continue;
        dfs(i.x, v, i.y);
        if(sz[_f(v)]+sz[_f(i.x)]>=x){
            _u(v, i.x);
            sz[_f(v)]-=x;
            res.push_back(i.y);
        }else{
            later.push(i.x);
        }
    }
    tout[v]=++timer;
    while(!later.empty()&&tin[later.top()]>=tin[v]&&tout[later.top()]<=tout[v]&&sz[_f(pp[later.top()].x)]+sz[_f(later.top())]>=x){
        _u(pp[later.top()].x, later.top());
        sz[_f(later.top())]-=x;
        res.push_back(pp[later.top()].y);
        later.pop();
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m >> x;
    ll sai=0;
    for(ll i = 1;i<=n;i++){
        cin >> a[i];
        sai+=a[i];
        dsu[i]=i;
        sz[i]=a[i];
    }
    for(ll a, b, i=0;i<m;i++){
        cin >> a >>b;
        d[a].push_back({b, i});
        d[b].push_back({a, i});
    }
    if(sai<x*(n-1)){
        cout<<"NO\n";
        return 0;
    }
    dfs(1);
    assert(later.empty());
    cout<<"YES\n";
    for(auto i : res) cout<<i+1<<'\n';
}