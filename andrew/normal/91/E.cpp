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
#define pii pair<int,int>
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

struct line{
    ll k, b;
};

vector <ll> t[MAXN], pos[MAXN];

inline bool operator < (line a, line b){
    if(a.k < b.k)return 1;
    if(a.k > b.k)return 0;
    return (a.b > b.b);
}

ll divide(ll a, ll b){
    if(a * b > 0)return a / b + (a % b > 0);
    return a / b;
}

vector <line> a;

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        t[v].p_b(tl);
        pos[v].p_b(-1e16);
        return;
    }
    ll tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build((v << 1) + 1, tm + 1, tr);

    ll uka = 0, ukb = 0;

    vector <ll> musor;

    while(uka < t[v << 1].size() && ukb < t[(v << 1) + 1].size()){
        if(a[t[v << 1][uka]] < a[t[(v << 1) + 1][ukb]]){
            musor.p_b(t[v << 1][uka]);
            uka++;
        }else{
            musor.p_b(t[(v << 1) + 1][ukb]);
            ukb++;
        }
    }

    while(uka < t[v << 1].size()){
        musor.p_b(t[v << 1][uka]);
        uka++;
    }

    while(ukb < t[(v << 1) + 1].size()){
        musor.p_b(t[(v << 1) + 1][ukb]);
        ukb++;
    }

    t[v].p_b(musor.front());
    pos[v].p_b(-1e16);

    for(auto i : musor){
        if(a[t[v].back()].k == a[i].k)continue;
        ll x = -1e16;

        while(1){
            x = divide(a[t[v].back()].b - a[i].b, a[i].k - a[t[v].back()].k);
            if(x > pos[v].back())break;
            t[v].pop_back();
            pos[v].pop_back();
        }

        t[v].p_b(i);
        pos[v].p_b(x);
    }

    musor.clear();
}

ll f(line a, ll x){
    return a.b + x * a.k;
}

pll get(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if(l > r)return {-1e18, -1e18};
    if(tl == l && tr == r){
        ll le = 0, ri = t[v].size() - 1;
        while(le < ri){
            ll mid = (le + ri) >> 1;
            if(pos[v][mid + 1] <= x)le = mid + 1; else ri = mid;
        }
        return {f(a[t[v][le]], x), t[v][le]};
    }
    ll tm = (tl + tr) >> 1;
    return max(get(v << 1, tl, tm, l, min(r, tm), x), get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, x));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++){
        ll k, b;
        cin >> b >> k;
        a[i].k = k;
        a[i].b = b;
    }

    build(1, 1, n);
    while(q--){
        ll l, r, t;
        cin >> l >> r >> t;
        cout << get(1, 1, n, l, r, t).se << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}