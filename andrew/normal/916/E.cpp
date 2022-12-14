#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5 + 6;
const ll inf = 2e9;
const ll M = 300000;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll t[MAXN], t1[MAXN];

void push(ll &v, ll &tl, ll &tr, ll &tm){
    t[v << 1] += t1[v] * (tm - tl + 1);
    t[v << 1 | 1] += t1[v] * (tr - tm);
    t1[v << 1] += t1[v];
    t1[v << 1 | 1] += t1[v];
    t1[v] = 0;
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        t[v] += (tr - tl + 1) * val;
        t1[v] += val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    push(v, tl, tr, tm);
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    push(v, tl, tr, tm);
    return get(v << 1, tl, tm, l, min(r, tm)) + get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
}

ll tin[MAXN], tout[MAXN], stn, deep[MAXN], root = 1, p[N][17], n;

vector <ll> v[MAXN];

void dfs(ll x, ll pr = 0){
    p[x][0] = pr;
    for(int i = 1; i < 17; i++){
        p[x][i] = p[p[x][i - 1]][i - 1];
        if(!p[x][i])break;
    }
    tin[x] = ++stn;
    deep[x] = deep[pr] + 1;
    for(auto to : v[x])if(to != pr)dfs(to, x);
    tout[x] = stn;
}

bool is_less(ll a, ll b){
    return tin[b] <= tin[a] && tout[a] <= tout[b];
}

ll lca(ll a, ll b){
    if(is_less(a, b))return b;
    if(is_less(b, a))return a;
    for(int i = 16; i >= 0; i--)if(!is_less(b, p[a][i]))a = p[a][i];
    return p[a][0];
}

ll get_pre(ll a, ll b){
    for(int i = 16; i >= 0; i--)if(!is_less(b, p[a][i]))a = p[a][i];
    return a;
}


ll get_lca(ll a, ll b){
    ll temp_a, temp_b, temp_c;
    temp_a = lca(a, b);
    temp_b = lca(a, root);
    temp_c = lca(b, root);
    return max(m_p(deep[temp_a], temp_a),
           max(m_p(deep[temp_b], temp_b), m_p(deep[temp_c], temp_c))).se;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    tout[0] = 1e9;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    ll q;
    cin >> n >> q;
    vector <ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        modify(1, 1, n, tin[i], tin[i], a[i]);
    }

    while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll vertex;
            cin >> vertex;
            root = vertex;
        }else if(t == 2){
            ll a, b, val;
            cin >> a >> b >> val;
            ll Lca = get_lca(a, b);
            if(Lca == root)modify(1, 1, n, 1, n, val);
            else if(!is_less(root, Lca)){
                modify(1, 1, n, tin[Lca], tout[Lca], val);
            }else{
                modify(1, 1, n, 1, n, val);
                ll vertex_pre_build = get_pre(root, Lca);
                modify(1, 1, n, tin[vertex_pre_build], tout[vertex_pre_build], -val);
            }
        }else{
            ll vertex;
            cin >> vertex;
            if(vertex == root){
                cout << get(1, 1, n, 1, n) << "\n";
            }else if(!is_less(root, vertex)){
                cout << get(1, 1, n, tin[vertex], tout[vertex]) << "\n";
            }else{
                ll vertex_pre_build = get_pre(root, vertex);
                cout << get(1, 1, n, 1, n) - get(1, 1, n, tin[vertex_pre_build], tout[vertex_pre_build]) << "\n";
            }
        }
    }

    return 0;
}