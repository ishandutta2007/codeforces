#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2007;
ld val[maxn][maxn];
int dp[maxn][maxn];

int mod = 1e9 + 7;

int add(int x, int y) {
    return (x + y) % mod;
}

int mul(int x, int y) {
    return (x * 1ll * y) % mod;
}

int divv(int x, int y) {
    if (y == 2) {
        if (x % 2 == 1) {
            x += mod;
        }
        return x / 2;
    } else {
        assert(0);
    }
}

void prec() {
    for (int i = 1; i < maxn; i++) {
        val[i][0] = 0;
        dp[i][0] = 0;
        val[i][i] = i;
        dp[i][i] = i;
        for (int e = 1; e < i; e++) {
            if (val[i - 1][e] - val[i - 1][e - 1] > 2) {
                val[i][e] = val[i - 1][e - 1] + 1;
                dp[i][e] = add(dp[i - 1][e - 1], 1);
            } else {
                val[i][e] = (val[i - 1][e - 1] + val[i - 1][e]) / 2;
                dp[i][e] = divv(add(dp[i - 1][e - 1], dp[i - 1][e]), 2);
            }
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << mul(dp[n][m], k) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prec();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}