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

ll t[MAXN], tk[MAXN], ta[MAXN], p1[MAXN];

ll a[MAXN], k[MAXN], tkek[MAXN];

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        k[tl] += k[tl - 1];
        t[v] = ta[v] = a[tl] - k[tl];
        tk[v] = k[tl];
    }else{
        ll tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build((v << 1) + 1, tm + 1, tr);
        t[v] = t[v << 1] + t[(v << 1) + 1];
        tk[v] = min(tk[v << 1], tk[(v << 1) + 1]);
        ta[v] = max(ta[v << 1], ta[(v << 1) + 1]);
    }
}

ll pos, n;

void push(ll v, ll tl, ll tr){
    ll tm = (tl + tr) >> 1;
    ll val = p1[v];
    t[v << 1] = (tm - tl + 1) * val;
    ta[v << 1] = val;
    p1[v << 1] = val;
    t[(v << 1) + 1] = (tr - tm) * val;
    ta[(v << 1) + 1] = val;
    p1[(v << 1) + 1] = val;
    p1[v] = -1e18;
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(tl == l && tr == r){
        t[v] = (tr - tl + 1) * val;
        ta[v] = val;
        p1[v] = val;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(p1[v] != -1e18)push(v, tl, tr);
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = t[v << 1] + t[(v << 1) + 1];
    tk[v] = min(tk[v << 1], tk[(v << 1) + 1]);
    ta[v] = max(ta[v << 1], ta[(v << 1) + 1]);
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    if(p1[v] != -1e18)push(v, tl, tr);
    return get(v << 1, tl, tm, l, min(r, tm)) + get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

ll G;

void dfs(ll v, ll tl, ll tr){
    if(ta[v] < G)return;
    if(tl == tr){
        pos = tl;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(p1[v] != -1e18)push(v, tl, tr);
    if(ta[v << 1] >= G)dfs(v << 1, tl, tm); else
    dfs((v << 1) + 1, tm + 1, tr);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;

    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 2; i <= n; i++)cin >> k[i];
    k[1] = 0;
    build(1, 1, n);
    for(int i = 0; i < MAXN; i++)p1[i] = -1e18;

    ll sum = 0;

    for(int i = 1; i <= n; i++)tkek[i] = tkek[i - 1] + k[i];

    ll q;
    cin >> q;
    while(q--){
        char T;
        cin >> T;
        if(T == 's'){
            ll l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) + tkek[r] - tkek[l - 1] << "\n";
        }else{
            ll i, x;
            cin >> i >> x;
            x += get(1, 1, n, i, i);
            G = x;
            pos = n + 1;
            //modify(1, 1, n, i, i, x);
            dfs(1, 1, n);
            modify(1, 1, n, i, pos - 1, x);
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}