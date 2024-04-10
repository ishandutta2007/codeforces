#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int MOD = 998244353;

int Pow(int x, int y) {
    int ret = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) {
            ret = (int64_t) ret * x % MOD;
        }
        x = x * (int64_t) x % MOD;
    }
    return ret;
}

int invMod(int x) {
    return Pow(x, MOD - 2);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int _a, _b;
    cin >> n >> _a >> _b;
    int p = _a * (int64_t) invMod(_b) % MOD;
    vector<int> powP(2 * n + 4);
    powP[0] = 1;
    for (int i = 1; i < SZ(powP); ++i) {
        powP[i] = powP[i - 1] * (int64_t) p % MOD;
    }
    vector<int> powNotP(2 * n + 4);
    powNotP[0] = 1;
    for (int i = 1; i < SZ(powNotP); ++i) {
        powNotP[i] = powNotP[i - 1] * (int64_t) (1 - p) % MOD;
    }
    vector<vector<int>> chPow(n + 1, vector<int>(n + 1));
    chPow[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        chPow[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            chPow[i][j] = (chPow[i - 1][j] * (int64_t) powNotP[j] + chPow[i - 1][j - 1] * (int64_t) powP[i - j]) % MOD;
        }
    }
    vector<int> dp(n + 1, 0);
    vector<int> exp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int addp = 0;
        for (int j = 1; j < i; ++j) {
            addp = (addp + chPow[i][j] * (int64_t) dp[j]) % MOD;
        }
        dp[i] = (1 - addp) % MOD;
        int add = 0;
        for (int j = 1; j < i; ++j) {
            add = (add + chPow[i][j] * (int64_t) dp[j] % MOD * (exp[i - j] + exp[j] - (i - j) * (i - j - 1) / 2LL)) % MOD;
        }
        int v = i * (i - 1) / 2;
        exp[i] = (v + add) * (int64_t) invMod((1 - dp[i]) % MOD) % MOD;
    }
    int ans = exp[n];

    ans %= MOD;
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << '\n';
}