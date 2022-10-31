//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 200600;
const ll C = 100;
pll a[N];
ll r[N];
vector<pll> active[N];
vector<pair<ll, pll>> g[C];
ll an[N];
ll cnt1[C], scntc[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	for(ll i = 0;i<n;i++){
        cin >> a[i].x >> a[i].y;
        an[i]=-1;
	}
	for(ll i = 0;i<m;i++){
        ll o, p;
        cin >> o >> p;
        --p;
        if(o==1){
            an[p]=i;
        }else{
            active[p].push_back({an[p], i-1});
            an[p]=-1;
        }
	}
    for(ll i = 0;i<n;i++){
        if(an[i]!=-1) active[i].push_back({an[i], m-1});
    }
    for(ll i = 0;i<n;i++){
        ll s = a[i].x + a[i].y;
        if(s>=C){
            for(auto j : active[i]){
                for(ll u = j.x+a[i].x;u<=j.y;u+=s){
                    r[u]++;
                    r[min(j.y, u+a[i].y-1)+1]--;
                }
            }
        }else{
            for(auto j : active[i]){
                ll sz = j.y-j.x+1;
                if(sz>=s) g[s].push_back({a[i].x, {j.x, sz/s}});
                ll l = sz%s;
                if(l>a[i].x){
                    l-=a[i].x;
                    r[j.y-l+1]++;
                    r[j.y+1]--;
                }
            }
        }
    }
    for(ll i = 1;i<m;i++) r[i]+=r[i-1];
    for(ll s=2;s<C;s++){
        for(ll j = 0;j<s;j++) cnt1[j]=0;
        for(auto i:g[s]){
            ll f = (i.y.x + i.x)%s;
            ll t = (i.y.x + s-1)%s;
            scntc[i.y.x+i.x]++;
            scntc[i.y.x+s]--;
            scntc[i.y.x+s*i.y.y+i.x]--;
            scntc[i.y.x+s+s*i.y.y]++;
        }
        ll cc=0;
        for(ll i = 0;i<m;i++){
            cc+=scntc[i];
            cnt1[i%s]+=cc;
            r[i]+=cnt1[i%s];
            scntc[i]=0;
        }
    }
    for(ll i = 0;i<m;i++) cout<<r[i]<<'\n';
}