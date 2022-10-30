// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], pf[N], id=0;
map<ll, ll> can;
queue<pll> qq;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ++id;
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n;i++) cin >> a[i];
        sort(a, a+n);
        for(ll i = 0;i<n;i++){
            pf[i]=a[i]+(i?pf[i-1]:0);
        }
        qq.push({0, n-1});
        while(!qq.empty()){
            pll now = qq.front(); qq.pop();
            ll l =now.x, r=now.y;
            ll sum = pf[r]-(l?pf[l-1]:0);
            can[sum]=id;
            ll mid = (a[l]+a[r])>>1;
            ll kl = l, kr = r+1;
            while(kr-kl>1){
                ll km = (kl+kr)>>1;
                if(a[km]<=mid) kl=km;
                else kr=km;
            }
            ll k = kl;
            if(k==r) continue;
            if(a[l]!=a[k]) qq.push({l, k});
            else can[(k-l+1)*a[l]] = id;
            if(a[k+1]!=a[r]) qq.push({k+1, r});
            else can[(r-k)*a[r]] = id;
        }
        while(m--){
            ll a;
            cin >> a;
            if(can[a]==id) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}