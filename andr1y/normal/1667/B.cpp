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
const ll N = 5e5+20;
ll a[N], dp[N];
random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution<ll> uid(1ll, 148814881489ll);
struct dk{
    ll x, v, y, z;
    dk *l = nullptr, *r=nullptr;
    dk (ll x, ll v) : x(x), v(v), y(uid(gen)), z(v){

    }
    void upd(){
        z = v;
        if(l) z=max(z, l->z);
        if(r) z=max(z, r->z);
    }
};
dk* merge(dk *a, dk *b){
    if(!a) return b;
    if(!b) return a;
    if(a->y > b->y){
        a->r = merge(a->r, b);
        a->upd();
        return a;
    }else{
        b->l = merge(a, b->l);
        b->upd();
        return b;
    }
}
pair<dk*,dk*> split(dk *a, ll k){
    if(!a) return {nullptr,nullptr};
    if(a->x < k){
        auto p = split(a->r, k);
        a->r = p.first;
        a->upd();
        return {a, p.second};
    }else{
        auto p = split(a->l, k);
        a->l = p.second;
        a->upd();
        return {p.first, a};
    }
}
dk *root;
void insert(ll k, ll v){
    auto p = split(root, k);
    dk *z = new dk(k,v);
    root = merge(p.first, merge(z, p.second));
}
ll get(ll k){
    auto p =split(root, k);
    ll r = (p.first?p.first->z:-inf);
    root=merge(p.first, p.second);
    return r;
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        root = nullptr;
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        dp[0] = (a[0] > 0 ? 1 : (a[0] == 0 ? 0 : -1));
        insert(0, 1);
        insert(a[0],dp[0]);
        ll s=a[0];
        for(ll i = 1;i<n;i++){
            s+=a[i];
            dp[i] = dp[i-1]+   (a[i] > 0 ? 1 : (a[i] == 0 ? 0 : -1))    ;
            ll f = get(s);
            dp[i] = max(dp[i], f + i);
            insert(s, dp[i]-i);
        }
        cout<<dp[n-1]<<'\n';
    }
}