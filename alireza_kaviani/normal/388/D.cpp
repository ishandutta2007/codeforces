#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

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

const ll MAXN = 1e6 + 10;
const ll LOG = 31;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , dp[LOG][LOG][2];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    //if(n != 2)  return 0;
    dp[LOG - 1][0][1] = 1;
    for(int i = LOG - 2 ; i >= 0 ; i--){
        dp[i][0][0] = ((1 << i) <= n);
        dp[i][0][1] = ((1 << i) > n);
        for(int j = 1 ; j < LOG ; j++){
            if(n & (1 << i)){
                dp[i][j][0] = (dp[i + 1][j][0] * (1 << j) + dp[i + 1][j - 1][0] + dp[i + 1][j][1] * (1 << j - 1)) % MOD;
                dp[i][j][1] = (dp[i + 1][j][1] * (1 << j - 1) + dp[i + 1][j - 1][1]) % MOD;
            }
            else{
                dp[i][j][0] = (dp[i + 1][j][0] * (1 << j) + dp[i + 1][j - 1][0]) % MOD;
                dp[i][j][1] = dp[i + 1][j][1] * (1 << j - 1) % MOD;
            }
        }
        /*for(int j = 0 ; j < LOG ; j++){
            cout << i << sep << j << sep << dp[i][j][0] << sep << dp[i][j][1] << endl;
        }*/
    }
    ll ans = 0;
    for(int i = 0 ; i < LOG ; i++)  ans += dp[0][i][0] + dp[0][i][1];
    cout << ans % MOD << endl;

    return 0;
}
/*

*/