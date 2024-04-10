// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll inf = 0x3fff3fff3fff3fff;
const ll M = 1e9+7;
ll a[N];
vector<ll> d[N];
vector<ll> rt[N];
bool was[N];
ll timer=0;
ll tin[N], tout[N];
void dfs(ll v){
    was[v]=1;
    tin[v]=++timer;
    for(auto i : d[v]){
        if(!was[i]) dfs(i);
    }
    tout[v]=++timer;
}
pll srt[N];
ll cmp[N], cmc=0;
bool ban[N];
vector<ll> fc[N];
void color(ll v, ll cc){
    ban[v]=1;
    cmp[v]=cc;
    fc[cc].push_back(v);
    for(auto i: rt[v]){
        if(!ban[i]) color(i, cc);
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n;
    for(ll i = 1;i<=n;i++){
        cin >> a[i];
    }
    cin >> m;
    for(ll a, b, i =0;i<m;i++){
        cin >> a >> b;
        d[a].push_back(b);
        rt[b].push_back(a);
    }
    for(ll i = 1;i<=n;i++){
        if(!was[i]) dfs(i);
    }
    for(ll i = 1;i<=n;i++){
        srt[i-1] = {tout[i], i};
    }
    sort(srt, srt+n, greater<pll>());
    for(ll q=0;q<n;q++){
        if(ban[srt[q].y]) continue;
        cmc++;
        color(srt[q].y, cmc);
    }
    ll r1=0, r2=1;
    for(ll i = 1;i<=cmc;i++){
        ll mv=inf, mc=0;
        for(auto j : fc[i]){
            if(a[j]<mv) mv=a[j], mc=1;
            else if(a[j]==mv) mc++;
        }
        r1+=mv, r2=(r2*mc)%M;
    }
    cout<<r1<<' '<<r2;
}