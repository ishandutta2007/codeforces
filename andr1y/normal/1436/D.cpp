// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
vector<ll> d[N];
ll a[N], pd[N], sz[N];
void dfs(ll v = 1){
    pd[v]=a[v];
    sz[v]=(d[v].empty()?1:0);
    for(auto i : d[v]){
        dfs(i);
        pd[v]+=pd[i];
        sz[v]+=sz[i];
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll a, i = 2;i<=n;i++){
        cin >> a;
        d[a].push_back(i);
    }
    for(ll i = 1;i<=n;i++) cin >> a[i];
    dfs();
    ll l = -1, r = 1ll*10000*10000*10000*10000;
    while(r-l>1){
        ll m = (l+r)>>1;
        bool ok = 1;
        for(ll i = 1;i<=n;i++) ok=ok&&((pd[i]+sz[i]-1)/sz[i]<=m);
        if(ok) r = m;
        else l=m;
    }
    cout<<r;
}