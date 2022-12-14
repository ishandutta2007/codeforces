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
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll t[MAXN];

void modify(ll v, ll tl, ll tr, ll pos, ll val){
    if(tl == tr)t[v] = pw(val);
    else{
        ll tm = (tl + tr) >> 1;
        if(pos <= tm)modify(v << 1, tl, tm, pos, val);
        else modify((v << 1) + 1, tm + 1, tr, pos, val);
        t[v] = t[v << 1] | t[(v << 1) + 1];
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)return 0;
    if(tl == l && tr == r)return t[v];
    ll tm = (tl + tr) >> 1;
    return get(v << 1, tl, tm, l, min(r, tm)) | get((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    //freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);

   string s;
   cin >> s;

   ll n = s.size();
   for(int i = 1; i <= n; i++)modify(1, 1, n, i, s[i - 1] - 'a');

   ll q;
   cin >> q;

   while(q--){
        ll t;
        cin >> t;
        if(t == 1){
            ll pos;
            char val;
            cin >> pos >> val;
            modify(1, 1, n, pos, val - 'a');
        }else{
            ll l, r;
            cin >> l >> r;
            cout << __builtin_popcountll(get(1, 1, n, l, r)) << "\n";
        }
   }

    return 0;
}