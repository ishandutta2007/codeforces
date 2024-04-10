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
 
ll page(ll x, ll k){
    ll res = x / k;
    if(x % k)res++;
    return res;
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m, k;
    cin >> n >> m >> k;
 
    vector <ll> p(m + 1);
 
    for(int i = 1; i <= m; i++)cin >> p[i];
 
    ll ans = 0, kol = 0;
 
    ll uk = 1;
 
    while(uk <= m){
        ll uk1 = uk;
        while(uk1 < m && page(p[uk] - kol, k) == page(p[uk1 + 1] - kol, k))uk1++;
        ans++;
        kol += uk1 - uk + 1;
        uk = uk1 + 1;
    }
 
    cout << ans << "\n";
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}