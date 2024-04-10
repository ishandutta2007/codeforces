#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define delete kek_void

using namespace std;
using namespace __gnu_pbds;
typedef int ll;
typedef long double ld;
const ll MAXN = 1323456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


vector <ll> v[MAXN];

ll tin[MAXN], tout[MAXN], kol[MAXN], stn, mx[MAXN], ans[MAXN], wh[MAXN];

vector <ll> a;

set <pll> s[MAXN];
ll p[MAXN];

void modify(ll v, ll tl, ll tr, ll pos, pll val){
    if(tl == tr)s[v].insert(val); else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val);
        else modify((v << 1) + 1, tm + 1, tr, pos, val);
        s[v].insert(val);
    }
}

void delete(ll v, ll tl, ll tr, ll pos, pll val){
    if(tl == tr)s[v].erase(val); else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)delete(v << 1, tl, tm, pos, val);
        else delete((v << 1) + 1, tm + 1, tr, pos, val);
        s[v].erase(val);
    }
}

void dfs(ll x, ll pr = 0){
    tin[x] = ++stn;
    a.p_b(x);
    kol[x] = 1;
    for(auto to : v[x])if(to != pr)dfs(to, x), kol[x] += kol[to];

    for(auto to : v[x])if(to != pr)mx[x] = max(mx[x], kol[to]);

    tout[x] = stn;
}

void find(ll v, ll tl, ll tr, ll l, ll r, pll val){
    if(l > r)return;
    if(tl == l && tr == r){
        while(!s[v].empty() && s[v].begin() -> fi <= val.fi){
            pll xe = *s[v].begin();
            ans[xe.se] = val.se;
            delete(1, 0, 3e5, kol[xe.se] / 2, xe);
        }
        return;
    }
    ll tm = (tl + tr) >> 1;
    find(v << 1, tl, tm, l, min(r, tm), val);
    find((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
}

void go(ll x, ll pr = 0){
    find(1, 0, 3e5, mx[x], 3e5, {kol[x], x});
    if(mx[x] <= kol[x] / 2)ans[x] = x; else
    modify(1, 0, 3e5, kol[x] / 2, {kol[x] - (kol[x] / 2), x});
    for(auto to : v[x])if(to != pr)go(to, x);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    a.p_b(0ll);
    for(int i = 2; i <= n; i++){
        ll x;
        cin >> x;
        v[i].p_b(x);
        v[x].p_b(i);
    }

    dfs(1ll);
    go(1ll);

    while(q--){
        ll x;
        cin >> x;
        cout << ans[x] << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}