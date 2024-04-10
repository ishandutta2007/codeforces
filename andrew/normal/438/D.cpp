#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)
#define f(x) (1ll << (x))

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll t[MAXN], p[MAXN];
vector <ll> a;

void build(ll v, ll tl, ll tr){
    if(tl == tr)t[v] = p[v] = a[tl]; else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        t[v] = t[v << 1] + t[(v << 1) + 1];
        p[v] = max(p[v << 1], p[(v << 1) + 1]);
    }
}

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)t[v] = p[v] = val; else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify((v << 1) + 1, tm + 1, tr, pos, val);
        t[v] = t[v << 1] + t[(v << 1) + 1];
        p[v] = max(p[v << 1], p[(v << 1) + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, min(r, tm)) + get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

ll mod;

void inst(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return;
    if(p[v] < mod)return;
    if(tl == tr){
        p[v] %= mod;
        t[v] %= mod;
        return;
    }
    ll tm = (tl + tr) >> 1;
    inst(v << 1, tl, tm, l, min(r, tm));
    inst((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = t[v << 1] + t[(v << 1) + 1];
    p[v] = max(p[v << 1], p[(v << 1) + 1]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, q;
    cin >> n >> q;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    build(1, 1, n);

    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }else if(t == 2){
            ll l, r;
            cin >> l >> r >> mod;
            inst(1, 1, n, l, r);
        }else{
            ll pos, val;
            cin >> pos >> val;
            modify(1, 1, n, pos, val);
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}