#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+20;
multiset<pll, greater<pll>> comps;
ll p[N], mx[N], a[N];
ll _f(ll v){
    return p[v] == v ? v : p[v] = _f(p[v]);
}
void _u(ll a, ll b){
    a=_f(a), b = _f(b);
    if(a==b) return;
    p[b] = a;
    comps.erase({mx[b], b});
    comps.erase({mx[a], a});
    mx[a] = max(mx[a], mx[b]);
    comps.insert({mx[a], a});
}

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            a[i]--;
            p[i]=i;
            mx[i]=i;
        }
        comps.clear();
        for(ll i = 0;i<n;i++){
            //comps.insert({mx[i], i});
            vector<ll> qq;
            while(comps.size() && comps.begin()->x > a[i]){
                qq.push_back(comps.begin()->y);
                comps.erase(comps.begin());
            }
            comps.insert({a[i], a[i]});
            for(auto j : qq) _u(a[i], j);
        }
        cout<<comps.size()<<'\n';
    }
}