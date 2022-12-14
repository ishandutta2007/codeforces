#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll mod = 1e9 + 7;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

vector <ll> v[MAXN], v1[MAXN];

vector <ll> G[MAXN], c;

ll id, gr[MAXN], p[100001][21], pr[MAXN], pg[MAXN];

ll fl[MAXN];

ll bp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n & 1)(res *= a) %= mod;
        (a *= a) %= mod;
        n >>= 1;
    }
    return res;
}

void dfs(ll x, ll pe){
    if(fl[x] == 1){
        id++;
        pg[id] = pr[x];
        for(int i = c.size(); i > 0; ){
            i--;
            G[id].p_b(c[i]);
            gr[c[i]] = id;
            if(c[i] == x)break;
        }
        reverse(all(G[id]));
        return;
    }
    if(fl[x] == 2)return;
    fl[x] = 1;
    pr[x] = pe;
    c.p_b(x);
    for(auto to : v[x])if(to != pe)dfs(to, x);
    c.pop_back();
    fl[x] = 2;
}

ll tin[MAXN], tout[MAXN], stn, deep[MAXN], val[MAXN];

void go(ll x, ll gl = 0){
    tin[x] = ++stn;
    gl += val[x];
    deep[x] = gl;
    for(auto to : v1[x])go(to, gl);
    tout[x] = stn;
}

bool is_less(ll a, ll b){
    if(tin[b] <= tin[a] && tout[a] <= tout[b])return 1;
    return 0;
}

ll lca(ll a, ll b){
    if(is_less(a, b))return b;
    if(is_less(b, a))return a;
    for(int i = 17; i >= 0; i--)if(!is_less(b, p[a][i]))a = p[a][i];
    return p[a][0];
}

ll f(ll a, ll b, ll c){
    return bp(2, deep[a] + deep[b] - 2 * deep[c] + val[c]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1ll, 0ll);

    for(int i = 1; i <= n; i++)if(!gr[i]){
        gr[i] = ++id;
        G[id].p_b(i);
        pg[id] = pr[i];
    }

    for(int i = 1; i <= id; i++){
        p[i][0] = gr[pg[i]];
        v1[p[i][0]].p_b(i);
        if(G[i].size() != 1)val[i] = 1;
    }

    go(0ll);

    for(int j = 1; j < 18; j++)
        for(int i = 1; i <= id; i++)p[i][j] = p[p[i][j - 1]][j - 1];


    ll t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;
        ll c = lca(gr[a], gr[b]);
        cout << f(gr[a], gr[b], c) << "\n";

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}