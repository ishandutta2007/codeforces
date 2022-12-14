/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 2e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , p[11] = {1 , 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29} , dp[11][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(ll i = 0 ; i < 11 ; i++){
        for(ll j = 0 ; j < MAXN ; j++)  dp[i][j] = INF;
    }
    dp[0][1] = 1;

    cin >> n;
    for(ll i = 1 ; i <= 10 ; i++){
        for(ll j = 1 ; j <= n ; j++){
            ll A = 1;
            for(ll k = 0 ; k <= 60 ; k++){
                if(j % (k + 1) == 0) {
                    if (INF / dp[i - 1][j / (k + 1)] >= A) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j / (k + 1)] * A);
                    }
                }
                if(INF / A < p[i])  break;
                A *= p[i];
            }
            //cout << i << sep << j << sep << dp[i][j] << endl;
        }
    }
    cout << dp[10][n] << endl;

    return 0;
}
/*

*/