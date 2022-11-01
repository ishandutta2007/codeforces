#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int MOD = 1e9 + 7;

int Pow(int x, int y, int MOD) {
    int ret = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) ret = (int64_t) ret * x % MOD;
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

    int m;
    cin >> m;

    int maxv = 200000;
    vector<int> count(maxv + 1, 0);

    vector<int> A(m);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        count[x]++;
        A[i] = x;
    }

    vector<int> p1(maxv + 2, 1), p2(maxv + 2, 1);
    for (int i = 1; i <= maxv; ++i) {
        p1[i] = (int64_t) p1[i - 1] * (count[i] + 1) % (MOD - 1);
    }
    for (int i = maxv; i > 0; --i) {
        p2[i] = (int64_t) p2[i + 1] * (count[i] + 1) % (MOD - 1);
    }

    int ans = 1;
    for (int i = 1; i <= maxv; ++i) {
        if (count[i] == 0) continue;
        int s = (int64_t) p1[i - 1] * p2[i + 1] % (MOD - 1);

        int dv = 1;
        for (int j = 1; j <= count[i]; ++j) {
            dv = (int64_t) dv * i % MOD;
            ans = (int64_t) ans * Pow(dv, s, MOD) % MOD;
        }
    }

    cout << ans << '\n';
}