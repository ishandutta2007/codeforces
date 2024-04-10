#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int XMAX = 101, MOD = 1e9 + 7;

int Pow(int x, int y, int mod) {
    int ret = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) ret = (int64_t) ret * x % mod;
        x = (int64_t) x * x % mod;
    }
    return ret;
}

struct Ways {
    int a[XMAX];
    Ways():
        a{0} {}
};

Ways init;

Ways solve(int p, int mod) {
    if (p == 1) return init;

    if (p % 2 == 0) {
        Ways ret, x = solve(p / 2, mod);
        int p1 = Pow(10, p / 2, mod);
        for (int i = 0; i < mod; ++i) {
            for (int j = 0; j < mod; ++j) {
                int r = (i * p1 + j) % mod;
                ret.a[r] = (ret.a[r] + (int64_t) x.a[i] * x.a[j]) % MOD;
            }
        }
        return ret;
    } else {
        Ways ret, x = solve(p - 1, mod);
        int p1 = 10 % mod;
        for (int i = 0; i < mod; ++i) {
            for (int j = 0; j < mod; ++j) {
                int r = (i * p1 + j) % mod;
                ret.a[r] = (ret.a[r] + (int64_t) x.a[i] * init.a[j]) % MOD;
            }
        }
        return ret;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, b, k, x;
    cin >> n >> b >> k >> x;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        init.a[p % x]++;
    }

    Ways ans = solve(b, x);
    cout << ans.a[k] << '\n';
}