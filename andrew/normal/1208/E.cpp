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

struct node{
    ll mx, mn, t1, zp;
};

ll f[MAXN], ans[MAXN], m[MAXN];

vector <ll> v[MAXN];

node T[5 * MAXN];

ll zapros;

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r)return;
    if(T[v].zp != zapros){
        T[v].t1 = T[v].mn = T[v].mx = -1e18;
        T[v].zp = zapros;
    }
    if(tl == l && tr == r){
        T[v].mn = max(T[v].mn, val);
        T[v].mx = max(T[v].mx, val);
        T[v].t1 = max(val, T[v].t1);
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(T[v].t1 != -1e18){
        if(T[v << 1].zp != zapros){
            T[v << 1].t1 = T[v << 1].mn = T[v << 1].mx = -1e18;
            T[v << 1].zp = zapros;
        }
        if(T[(v << 1) + 1].zp != zapros){
            T[(v << 1) + 1].t1 = T[(v << 1) + 1].mn = T[(v << 1) + 1].mx = -1e18;
            T[(v << 1) + 1].zp = zapros;
        }
        T[(v << 1) + 1].t1 = max(T[(v << 1) + 1].t1, T[v].t1);
        T[(v << 1) + 1].mn = max(T[(v << 1) + 1].mn, T[v].t1);
        T[(v << 1) + 1].mx = max(T[(v << 1) + 1].mx, T[v].t1);

        T[v << 1].t1 = max(T[v << 1].t1, T[v].t1);
        T[v << 1].mn = max(T[v << 1].mn, T[v].t1);
        T[v << 1].mx = max(T[v << 1].mx, T[v].t1);
    }
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    T[v].mn = min(T[v << 1].mn, T[(v << 1) + 1].mn);
    T[v].mx = max(T[v << 1].mx, T[(v << 1) + 1].mx);
}

void calc(ll v, ll tl, ll tr, ll val = -1e18){
    if(T[v].zp != zapros){
        T[v].t1 = T[v].mn = T[v].mx = -1e18;
        T[v].zp = zapros;
    }
    val = max(val, T[v].t1);
    if(max(val, T[v].mn) == max(val, T[v].mx)){
        f[tl] += max(val, T[v].mn);
        f[tr + 1] -= max(val, T[v].mn);
        return;
    }
    ll tm = (tl + tr) >> 1;
    calc(v << 1, tl, tm, val);
    calc((v << 1) + 1, tm + 1, tr, val);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, w;
    cin >> n >> w;
    w += 2;

    for(int i = 1; i < 5 * MAXN; i++){
        T[i].mx = -1e18;
        T[i].mn = -1e18;
        T[i].t1 = -1e18;
    }

    for(int i = 1; i <= n; i++){
        cin >> m[i];
        v[i].p_b(0ll);
        while(m[i]--){
            ll x;
            cin >> x;
            v[i].p_b(x);
        }
        v[i].p_b(0ll);
        m[i] = v[i].size();
    }

    ll sc = 0;


    for(int i = 1; i <= n; i++){
        zapros++;
        for(int j = 1; j <= m[i]; j++){
            ll le = j, ri = w - (m[i] - j);
            modify(1, 1, w, le, ri, v[i][j - 1]);
        }
        calc(1, 1, w);
    }

    for(int i = 1; i <= w; i++){
        sc += f[i];
        ans[i] = sc;
    }

    for(int i = 2; i < w; i++)cout << ans[i] << " ";
    cout << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}