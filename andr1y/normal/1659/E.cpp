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

struct dsu{
    vector<ll> p;
    vector<bool> sp;
    dsu(ll n, bool *s){
        p.resize(n);
        sp.resize(n);
        iota(p.begin(), p.end(), 0);
        for(ll i =0 ;i<n;i++) sp[i]=s[i];
    }
    ll _f(ll a){
        return p[a]==a?a:p[a]=_f(p[a]);
    }
    void unite(ll a, ll b){
        a=_f(a), b=_f(b);
        if(a==b) return;
        p[b]=a;
        sp[a]=sp[a] || sp[b];
    }
    bool istog(ll a, ll b){
        return _f(a) == _f(b);
    }
    bool ispec(ll a){
        return sp[_f(a)];
    }
};

dsu *simple[30], *hard[30];
bool spec[N];

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<30;i++) simple[i] = new dsu(n, spec);
    vector<pair<pll, ll>> ee;
    for(ll i = 0;i<m;i++){
        ll a, b,  w;
        cin >> a >> b >> w;
        --a, b--;
        for(ll j = 0;j<30;j++){
            if((w>>j)&1) simple[j]->unite(a, b);
        }
        if((~w)&1) spec[a] = 1, spec[b] = 1;
        else ee.push_back({{a,b},w});
    }
    for(ll i = 0;i<30;i++) hard[i] = new dsu(n, spec);
    for(auto [p,w] : ee){
        auto [a,b] = p;
        for(ll j = 1;j<30;j++) if((w>>j)&1) hard[j]->unite(a, b);
    }
    ll q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a>> b;
        --a, b--;
        bool r = false;
        for(ll i = 0;i<30&&!r;i++) if(simple[i]->istog(a,b)) r=true;
        if(r) {cout<<"0\n";continue;}
        for(ll i = 1;i<30&&!r;i++) if(hard[i]->ispec(a)) r=true;
        if(r) {cout<<"1\n";continue;}
        if(1) {cout<<"2\n";continue;}
    }
}