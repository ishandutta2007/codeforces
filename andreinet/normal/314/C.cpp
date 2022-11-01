#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005, VMAX = 1e6 + 11;
const int MOD = 1e9 + 7;

int aib[VMAX];
int lastAns[VMAX];

void update(int aib[], int pos, int val) {
    for (; pos < VMAX - 5; pos += pos & -pos) {
        aib[pos] = (aib[pos] + val) % MOD;
    }
}

int query(int aib[], int pos) {
    int ret = 0;
    for (; pos > 0; pos -= pos & -pos) {
        ret = (ret + aib[pos]) % MOD;
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

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;

        int p = (query(aib, x) + 1) % MOD;
        int add = (int64_t) p * x % MOD;
        update(aib, x, -lastAns[x]);
        update(aib, x, add);
        lastAns[x] = add;
    }
    for (int i = 1; i <= (int) (1e6); ++i) {
        ans = (ans + lastAns[i]) % MOD;
    }
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
}