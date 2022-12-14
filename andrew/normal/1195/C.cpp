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
const ll N = 3e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
ll dp[MAXN][2];
 
ll a[MAXN][2];
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
 
    for(int i = 1; i <= n; i++)cin >> a[i][0];
    for(int i = 1; i <= n; i++)cin >> a[i][1];
 
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][1 - j] + a[i][j]);
        }
    }
 
    cout << max(dp[n][0], dp[n][1]) << "\n";
 
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}