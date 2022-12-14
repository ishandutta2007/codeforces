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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

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

vector <pll> v[MAXN];

ll T;

const ll N = 1e6 + 5;

ll ans[MAXN], a[MAXN], xx[MAXN], t[MAXN];

ll p[4 * MAXN], p1[4 * MAXN];

ll n;

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr){
        p[v] += val;
        p1[v] += tl * val;
    }else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val); else modify((v << 1) + 1, tm + 1, tr, pos, val);
        p[v] = p[v << 1] + p[(v << 1) + 1];
        p1[v] = p1[v << 1] + p1[(v << 1) + 1];
    }
}

ll get(ll v, ll tl, ll tr, ll k){
    if(k < 1)return 0;
    //cout << v << " " << tl << " " << tr << " " << k << " " << p[v] << endl;
    if(k == p[v])return p1[v];

    if(tl == tr){
        return k * tl;
    }

    ll tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, min(k, p[v << 1])) + get((v << 1) + 1, tm + 1, tr, k - p[v << 1]);
}

void dfs(ll x, ll sc){
    modify(1, 1, N, t[x], xx[x]);
    ll xe = T - sc;
    ll l = 0, r = p[1];

    //cout << x << endl;

    while(l < r){
        ll c = (l + r) >> 1;
        if(c == l)c++;
        if(get(1, 1, N, c) <= xe)l = c; else r = c - 1;
    }
    //cout << x << " " << xe << " " << sc << " " << l << endl;

    a[x] = l;

    for(auto to : v[x])dfs(to.fi, sc + to.se * 2);
    modify(1, 1, N, t[x], -xx[x]);
}

void f(ll x){
    multiset <ll> s;

    if(v[x].empty()){
        ans[x] = a[x];
        return;
    }

    for(auto to : v[x]){
        f(to.fi);
        s.insert(ans[to.fi]);
    }

    ans[x] = a[x];

    if(x != 1)s.erase(--s.end());
    if(!s.empty())ans[x] = max(ans[x], *(--s.end()));

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> T;

    for(int i = 1; i <= n; i++)cin >> xx[i];
    for(int i = 1; i <= n; i++)cin >> t[i];

    for(int i = 2; i <= n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b({i, b});
    }

    dfs(1ll, 0ll);
    f(1ll);

    cout << ans[1] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}