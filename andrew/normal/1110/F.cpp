#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <pll> v[MAXN];

ll tin[MAXN], tout[MAXN], deep[MAXN], stn, n, ans[MAXN];

ll t[3 * MAXN], t1[3 * MAXN];

void push(ll v){
    t[v << 1] += t1[v];
    t1[v << 1] += t1[v];
    t[(v << 1) + 1] += t1[v];
    t1[(v << 1) + 1] += t1[v];
    t1[v] = 0;
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        t[v] += val;
        t1[v] += val;
        return;
    }
    if(t1[v])push(v);
    ll tm = (tl + tr) >> 1;
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v << 1], t[(v << 1) + 1]);
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 1e18;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    if(t1[v])push(v);
    return min(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

void dfs(ll x, ll pr){
    tin[x] = ++stn;

    sort(all(v[x]));

    for(auto to : v[x])if(to.fi != pr){
        deep[to.fi] = deep[x] + to.se;
        dfs(to.fi, x);
    }

    if(x != 1 && v[x].size() == 1){
        modify(1, 1, n, x, x, deep[x]);
    }else modify(1, 1, n, x, x, 1e18);

    tout[x] = stn;
}

struct query{
    ll l, r, time;
};

vector <query> QR[MAXN];

void go(ll x, ll pr){
    for(auto j : QR[x]){
        ans[j.time] = get(1, 1, n, j.l, j.r);
    }

    for(auto to : v[x])if(to.fi != pr){
        modify(1, 1, n, tin[to.fi], tout[to.fi], -to.se);
        modify(1, 1, n, 1, tin[to.fi] - 1, to.se);
        modify(1, 1, n, tout[to.fi] + 1, n, to.se);
        go(to.fi, x);
        modify(1, 1, n, tin[to.fi], tout[to.fi], to.se);
        modify(1, 1, n, 1, tin[to.fi] - 1, -to.se);
        modify(1, 1, n, tout[to.fi] + 1, n, -to.se);

    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll q;
    cin >> n >> q;

    for(int i = 2; i <= n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b({i, b});
        v[i].p_b({a, b});
    }

    dfs(1ll, 0ll);

    for(int i = 1; i <= q; i++){
        query New;
        ll x;
        cin >> x >> New.l >> New.r;
        New.time = i;
        QR[x].p_b(New);
    }

    go(1ll, 0ll);

    for(int i = 1; i <= q; i++)cout << ans[i] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}