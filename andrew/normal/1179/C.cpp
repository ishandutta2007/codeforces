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
const ll N = 1e6;
const ll MOD = 1e9 + 7;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}


ll t[4 * MAXN], t1[4 * MAXN];

void push(ll v){
    t[v << 1] += t1[v];
    t[(v << 1) + 1] += t1[v];
    t1[v << 1] += t1[v];
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
    ll tm = (tl + tr) >> 1;
    if(t1[v])push(v);
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v << 1], t[(v << 1) + 1]);
}

ll pos;

void _find(ll v, ll tl, ll tr){
    if(pos != -1)return;
    if(t[v] > -1)return;
    if(tl == tr){
        pos = tl;
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(t1[v])push(v);
    _find((v << 1) + 1, tm + 1, tr);
    _find(v << 1, tl, tm);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;

    cin >> n >> m;

    vector <ll> a(n + 1), b(m + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++)cin >> b[i];


    for(int i = 1; i <= n; i++){
        modify(1, 1, N, 1, a[i], -1);
    }

    for(int i = 1; i <= m; i++){
        modify(1, 1, N, 1, b[i], 1);
    }

    ll q;
    cin >> q;

    while(q--){
        ll tp;
        cin >> tp;
        if(tp == 1){
            ll i, x;
            cin >> i >> x;
            modify(1, 1, N, 1, a[i], 1);
            a[i] = x;
            modify(1, 1, N, 1, a[i], -1);
        }else{
            ll i, x;
            cin >> i >> x;
            modify(1, 1, N, 1, b[i], -1);
            b[i] = x;
            modify(1, 1, N, 1, b[i], 1);
        }

        if(t[1] > -1)cout << "-1\n"; else{
            pos = -1;
            _find(1, 1, N);
            cout << pos << "\n";
        }

    }

    return 0;
}