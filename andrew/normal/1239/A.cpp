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
#define sz(x) (int)x.size()
 
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
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll val1 = 2, val2 = 2;
    ll n, m;
    cin >> n >> m;
 
    ll mod = 1e9 + 7;
 
    for(int i = 1; i < n; i++){
        ll c = (val1 + val2) % mod;
        val1 = val2;
        val2 = c;
    }
 
    if(m == 1)vout(val2);
    if(m == 2)vout(val2 + 2);
    if(m == 3)vout(val2 + 4);
 
    ll dt1 = 2, dt2 = 4;
 
    ll ans = val2 + 4;
 
    ans %= mod;
    for(int i = 4; i <= m; i++){
        (ans += dt2) %= mod;
        ll c = (dt1 + dt2) % mod;
        dt1 = dt2;
        dt2 = c;
    }
 
    cout << ans << "\n";
 
    return 0;
}