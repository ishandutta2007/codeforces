#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int MOD = (int) 1e9 + 7;

int Pow(int x, int y) {
    int res = 1;
    for (;y > 0; y /= 2) {
        if (y & 1) {
            res = (int64_t) res * x % MOD;
        }
        x = (int64_t) x * x % MOD;
    }
    return res;
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

    int k, pa, pb;
    cin >> k >> pa >> pb;

    int pra = pa * ((int64_t) invMod(pa + pb)) % MOD;
    int prb = pb * ((int64_t) invMod(pa + pb)) % MOD;

    vector<vector<int>> prob(k + 2, vector<int>(2 * k + 1, 0));
    prob[1][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i + 1 <= k)  {
                prob[i + 1][j] = (prob[i + 1][j] + prob[i][j] * (int64_t) pra) % MOD;
            }
            prob[i][j + i] = (prob[i][j + i] + prob[i][j] * (int64_t) prb) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i < k; ++i) {
        for (int j = k; j <= 2 * k; ++j) {
            ans = (ans + prob[i][j] * (int64_t) j) % MOD;
        }
    }
    for (int j = 0; j < k; ++j) {
        int v = j + k;
        int add = (v - 1) * (int64_t) prb % MOD * invMod(1 - pra) % MOD * prob[k][j] % MOD;
        ans = (ans + add) % MOD;
        add = invMod(1 - pra) * (int64_t) prb % MOD * invMod(1 - pra) % MOD * prob[k][j] % MOD;
        ans = (ans + add) % MOD;
    }
    ans %= MOD;
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << '\n';
}