#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int Pow(int x, int y, int MOD) {
    int ret = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) {
            ret = (int64_t) ret * x % MOD;
        }
        x = (int64_t) x * x % MOD;
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MOD = 1e9 + 7;

    int n = 1 << 20;
    int m;
    cin >> m;

    vector<int> count(n, 0);
    while (m-- > 0) {
        int x;
        cin >> x;
        x = (n - 1) ^ x;
        count[x]++;
    }
    
    vector<int> dp1 = count;
    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i & (1 << j)) {
                dp1[i] += dp1[i ^ (1 << j)];
                dp1[i] %= MOD - 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dp1[i] = Pow(2, dp1[i], MOD);
    }
    for (int j = 0; j < 20; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            if (i & (1 << j)) {
                dp1[i] = (dp1[i] - dp1[i ^ (1 << j)] + MOD) % MOD;
            }
        }
    }
    cout << dp1[n - 1] << '\n';
}