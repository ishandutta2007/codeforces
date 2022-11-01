#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>


#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ll INF = 1e15 + 10;

const int LEN = 20;
const int MOD = 504;
const int DIGITS = 8;

ll dp[LEN][(1 << DIGITS)][MOD][2];

ll solveDP(ll x) {
    string xs;
    ll x1 = x;
    while (x1) {
        xs.pb(x1 % 10 + '0');
        x1 /= 10;
    }

    reverse(xs.begin(), xs.end());

    for (int i = 0; i <= (int)xs.size(); i++)
        for (int j = 0; j < (1 << DIGITS); j++)
            for (int mod = 0; mod < MOD; mod++)
                dp[i][j][mod][0] = dp[i][j][mod][1] = 0;
    dp[0][0][0][1] = 1;

    for (int len = 0; len < (int)xs.size(); len++) {
        for (int mask = 0; mask < (1 << DIGITS); mask++) {
            for (int r = 0; r < MOD; r++) {
                if (dp[len][mask][r][0]) {
                    for (int digit = 0; digit <= 9; digit++) {
                        if (len + 1 == (int)xs.size() &&
                            !(digit == 0 || digit == 5) && (mask & (1 << (5 - 2))))
                            continue;
                        dp[len + 1][mask | (digit >= 2 ? (1 << (digit - 2)) : 0)][(r * 10 + digit) % MOD][0] +=
                            dp[len][mask][r][0];
                    }
                }
                if (dp[len][mask][r][1]) {
                    for (int digit = 0; digit < xs[len] - '0'; digit++) {
                        if (len + 1 == (int)xs.size() &&
                            !(digit == 0 || digit == 5) && (mask & (1 << (5 - 2))))
                            continue;
                        dp[len + 1][mask | (digit >= 2 ? (1 << (digit - 2)) : 0)][(r * 10 + digit) % MOD][0] +=
                            dp[len][mask][r][1];

                    }
                    int digit = (xs[len] - '0');
                    if (!(len + 1 == (int)xs.size() &&
                            !(digit == 0 || digit == 5) && (mask & (1 << (5 - 2)))))
                    dp[len + 1][mask | (digit >= 2 ? (1 << (digit - 2)) : 0)][(r * 10 + digit) % MOD][1] +=
                        dp[len][mask][r][1];

                }
            }
        }
    }

    ll ans = 0;

    int len = xs.size();
    for (int mask = 0; mask < (1 << DIGITS); mask++) {
        for (int r = 0; r < MOD; r++) {
            bool ok = true;
            for (int i = 0; i < DIGITS && ok; i++)
                if ((mask & (1 << i)) && r % (i + 2) && i != 5 - 2)
                    ok = false;
            if (ok && dp[len][mask][r][0] + dp[len][mask][r][1]) {
                ans += (dp[len][mask][r][0] + dp[len][mask][r][1]);
            }
        }
    }
    return ans;

}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << solveDP(r) - solveDP(l - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
        solve();
}