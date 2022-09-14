#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef complex<double> Complex;

const double PI = acos(-1);
const ll INF = 1e13;

const int MAXN = 51;

ll dp[MAXN][MAXN][MAXN * 100];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("input.txt", "w", stdout);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> p(n);

    for (int i = 0; i < n; ++i) {
        // p[i].second = 100000000;
        cin >> p[i].first;
    }

    for (int i = 0; i < n; ++i) {
        // p[i].first = 1;
        cin >> p[i].second;
    }

    sort(all(p));
    reverse(all(p));

    for (int i = 0; i < n; ++i) {
        a[i] = p[i].first;
        b[i] = p[i].second;
        // cout << a[i] << " " << b[i] << endl;
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= 100 * (i - j); ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; ) {

        int rg = i;
        for (; rg < n && a[rg] == a[i]; ++rg);
        int len = rg - i;
        ll x = a[i];

        ll sum = 0;
        for (int u = i; u < rg; ++u) {
            sum += b[u];
        }

        for (int j = 0; j <= i; ++j) {  
            for (int k = 0; k <= 100 * (i - j); ++k) {
                if (dp[i][j][k] == INF) {
                    continue;
                }

                ll s = 0;

                for (int u = 0; u <= len; ++u) {
                    if (j + u > i - j) {
                        continue;
                    }

                    dp[rg][j + u][k + sum - s] = min(dp[rg][j + u][k + sum - s], 
                                                    dp[i][j][k] + (len - u) * x);

                    if (u < len) {
                        s += b[rg - 1 - u];
                    }
                }
            }
        }

        i = rg;
    }

    ll ans = INF;
    for (int j = 0; j <= n; ++j) {  
        for (int k = 1; k <= 100 * (n - j); ++k) {
            if (dp[n][j][k] < INF) {
                // cout << j << " " << k << endl;
                // cout << dp[n][j][k] << endl;
                // cout << (double)dp[n][j][k] / k << endl;
                ans = min(ans, (dp[n][j][k] * 1000 + k - 1) / k);
            }
        }
    }

    cout << ans << endl;

    return 0;
}