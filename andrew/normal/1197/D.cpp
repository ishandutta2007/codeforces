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
#define delete _delete

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e6;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];
    ll ans = 0, sc = 0;

    vector <ll> mx(21);

    for(auto &i : mx)i = -1e18;

    for(int i = 1; i <= n; i++){
        ll old = sc;
        sc += a[i];
        mx[i % m] = max(mx[i % m], -old + k * (ll(i / m)));
        for(int j = 0; j < m; j++){
            ll val = sc - k * (ll((i + 1) / m) + (j < (i + 1) % m));
            val += mx[j];
            ans = max(ans, val);
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}