/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-03-27 10:35:11
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 15e2 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , s , k , ps[MAXN] , A[MAXN] , L[MAXN] , dp[MAXN][MAXN];

ll check(ll x){
    memset(dp , 63 , sizeof(dp));
    memset(ps , 0 , sizeof(ps));
    for(ll i = 1 ; i <= n ; i++)    ps[i] = (A[i] <= x ? 1 : 0);
    partial_sum(ps , ps + MAXN , ps);
    dp[0][0] = 0;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 0 ; j <= i ; j++){
            dp[i][j] = dp[i - 1][j];
            if(L[i] != INF) dp[i][j] = min(dp[i][j] , dp[L[i] - 1][max(0LL , j - ps[i] + ps[L[i] - 1])] + 1);
        }
    }
    //cout << x << sep << dp[n][k] << endl;
    return dp[n][k] <= m;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(L , L + MAXN , INF);

    cin >> n >> s >> m >> k;
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
    for(ll i = 0 ; i < s ; i++){
        ll l , r;
        cin >> l >> r;
        for(ll j = l ; j <= r ; j++)    L[j] = min(L[j] , l);
    }

    ll l = 0 , r = MOD;
    while(r - l > 1){
        ll mid = l + r >> 1;
        if(check(mid))  r = mid;
        else    l = mid;
    }
    if(r == MOD)    cout << -1 << endl;
    else    cout << r << endl;

    return 0;
}
/*

*/