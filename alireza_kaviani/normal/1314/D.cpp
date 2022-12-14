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

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const ll MAXN = 80 + 10;
const ll LOG = 22;
const ll INF = 1e14;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, ans = INF, mark[MAXN], d[MAXN][MAXN], dp[5][6], Mn[5][5];
vector<pair<ll, ll>> mn[MAXN][MAXN];

ll solve(vector<ll> v) {
    ll m = SZ(v);
    for (ll i = 0; i < m; i++) fill(dp[i], dp[i] + 6, INF), mark[v[i]] = 1;
    //for(ll i = 0 ; i < m ; i++) cout << v[i] << sep;
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < m; j++) {
            for (pair<ll, ll> k : mn[v[i]][v[j]]) {
                if (!mark[k.Y]) {
                    Mn[i][j] = k.X;
                    break;
                }
            }
            //      cout << i << sep << j << sep << Mn[i][j] << endl;
        }
    }

    //cout << endl;
    dp[0][0] = 0;
    for (ll i = 1; i <= k / 2; i++) {
        for (ll j = 0; j < m; j++) {
            for (ll k = 0; k < m; k++) dp[j][i] = min(dp[j][i], dp[k][i - 1] + Mn[k][j]);
            //      cout << i << sep << j << sep << dp[j][i] << endl;
        }
    }
    //cout << "==========" << endl;
    for (ll i : v) mark[i] = 0;
    return dp[0][k / 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (ll i = 0; i < MAXN; i++) fill(d[i], d[i] + MAXN, INF);

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll k = 1; k <= max(n, 6LL); k++) {
                //cout << i << sep << j << sep << k << sep << d[i][k] + d[k][j] << endl;
                mn[i][j].push_back({d[i][k] + d[k][j], k});
            }
            Sort(mn[i][j]);
        }
    }

    ans = min(ans, solve({1}));
    for (ll i = 2; i <= n; i++) {
        ans = min(ans, solve({1, i}));
        for (ll j = i + 1; j <= n; j++) {
            ans = min(ans, solve({1, i, j}));
            for (ll k = j + 1; k <= n; k++) {
                ans = min(ans, solve({1, i, j, k}));
                for (ll l = k + 1; l <= n; l++) {
                    ans = min(ans, solve({1, i, j, k, l}));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
/*

*/