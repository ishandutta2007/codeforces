#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int MOD = (int) 1e9 + 7;

const int DM = 22;
const int NMAX = 2005;
const int MMAX = 300005;

int Pow(int x, int y) {
    int ret = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) ret = (int64_t) ret * x % MOD;
        x = (int64_t) x * x % MOD;
    }
    return ret;
}

int invMod(int x) {
    return Pow(x, MOD - 2);
}

int fact[MMAX], invFact[MMAX];

void precalc(int m) {
    fact[0] = 1;
    for (int i = 1; i <= m; ++i) {
        fact[i] = (int64_t) fact[i - 1] * i % MOD;
    }
    invFact[m] = invMod(fact[m]);
    for (int i = m - 1; i >= 0; --i) {
        invFact[i] = (int64_t) invFact[i + 1] * (i + 1) % MOD;
    }
}

inline int comb(int n, int k) {
    return (int64_t) fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

int dp[NMAX][DM];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m1, m2, n, s;
    cin >> m1 >> m2 >> n >> s;

    int m = m1 + m2 + 2;
    precalc(m);

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    int shift = 1;
    if (!A.empty() && A.front() == make_pair(1, 1)) {
        shift++;
    } else {
        A.insert(A.begin(), make_pair(1, 1));
    }
    if (!A.empty() && A.back() == make_pair(m1, m2)) {
    } else {
        A.insert(A.end(), make_pair(m1, m2));
        shift--;
    }
    
    n = SZ(A);
    for (int k = 1; k < DM - 1; ++k) {
        for (int i = 1; i < n; ++i) {
            int x = A[i].first, y = A[i].second;
            dp[i][k] += comb(x + y - 2, y - 1);
            dp[i][k] %= MOD;
            for (int j = 1; j < k; ++j) {
                dp[i][k] -= dp[i][j];
                dp[i][k] %= MOD;
            }
            for (int j = i + 1; j < n; ++j) {
                int nx = A[j].first, ny = A[j].second;
                if (x <= nx && y <= ny) {
                    dp[j][k] -= (int64_t) dp[i][k] * comb(nx - x + ny - y, ny - y) % MOD;
                    dp[j][k] %= MOD;
                }
            }
        }
    }

    vector<int> values(DM);
    for (int i = 0, x = s; i < DM; ++i) {
        values[i] = x;
        x = (x + 1) / 2;
    }
    while (shift > 0 && SZ(values) > 0) {
        values.erase(values.begin());
        shift--;
    }
    
    int ans = 0, sum = 0;
    for (int i = 0; i < SZ(values); ++i) {
        ans += (int64_t) dp[n - 1][i + 1] * values[i] % MOD;
        ans %= MOD;
        sum += dp[n - 1][i + 1];
        sum %= MOD;
    }
    ans += (comb(m1 + m2 - 2, m2 - 1) - sum) % MOD;
    ans %= MOD;
    ans = (int64_t) ans * invMod(comb(m1 + m2 - 2, m2 - 1)) % MOD;
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << '\n';
}