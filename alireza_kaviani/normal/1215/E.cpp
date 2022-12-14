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
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXA = 21;
const ll MAXN = 1e6 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], sum[MAXN], cnt[MAXN], cost[MAXA][MAXA], dp[(1 << MAXA)];
vector<ll> vec[MAXA];

int main() {
    fast_io;
    fill(dp, dp + (1 << MAXA), INF);

    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
        A[i]--;
        cnt[A[i]]++;
        sum[A[i]] += i;
        vec[A[i]].push_back(i);
    }

    for (ll i = 0; i < 20; i++) {
        for (ll j = 0; j < 20; j++) {
            for (ll k : vec[i]) {
                cost[i][j] += SZ(vec[j]) - (lower_bound(all(vec[j]), k) - vec[j].begin());
            }
        }
    }

    dp[0] = 0;
    for (ll i = 0; i < (1 << MAXA); i++) {
        for (ll j = 0; j < MAXA; j++) {
            if ((i & (1LL << j)) == 0) {
                ll x = 0;
                for (ll k = 0; k < MAXA; k++) {
                    if (i & (1LL << k)) x += cost[k][j];
                }
                dp[i | (1LL << j)] = min(dp[i | (1LL << j)], dp[i] + sum[j] - x - cnt[j] * (cnt[j] - 1) / 2);
            }
        }
    }
    cout << dp[(1 << MAXA) - 1] << endl;

    return 0;
}
/*

*/