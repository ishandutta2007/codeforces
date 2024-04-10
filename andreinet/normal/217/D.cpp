#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int MOD = (int) 1e9 + 7;

int cnt[125];

int ans = 0;

int cntThings = 0;

void back(int pos, int m, int ways, uint64_t dp, uint64_t dpInv, int have) {
    if (pos == m / 2 + 1) {
        ans = (ans + ways) % MOD;
        ++cntThings;
    } else {
        if (cnt[pos] > 0) {
            uint64_t ndp = dp | (dp >> pos) | (dp << pos) |
                (dpInv << ((m - 1) / 2 + 1 - pos)) |
                (dpInv >> (-((m - 1) / 2 + 1) - pos + m));
            ndp &= (1LLU << (m / 2 + 1)) - 1;
            uint64_t ndpInv = dpInv | (dpInv >> pos) | (dpInv << pos) |
                (dp >> (-pos + ((m - 1) / 2 + 1))) |
                (dp << (m - pos - ((m - 1) / 2 + 1)));
            ndpInv &= (1LLU << (m / 2 + 1)) - 1;
            ndp |= 1LLU << pos;
            ndpInv |= 1LLU << (m - pos - ((m - 1) / 2 + 1));
            if ((ndp & 1) == 0) {
                back(pos + 1, m, ways * (int64_t) cnt[pos] % MOD, ndp, ndpInv, have + 1);
            }
        }
        back(pos + 1, m, ways, dp, dpInv, have);
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        cnt[min(x % m, (m - x % m) % m)]++;
    }

    back(0, m, 1, 0LLU, 0LLU, 0);
    cout << ans << '\n';
}