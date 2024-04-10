#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int Pow(int x, int y, int MOD) {
    int ret = 1;
    for (; y > 0; y /= 1) {
        if (y & 1) ret = ret * (int64_t) x % MOD;
        x = x * (int64_t) x % MOD;
    }
    return ret;
}

int invMod(int x, int Mod) {
    return Pow(x, Mod - 2, Mod);
}

int dp[405][405][405];

int test1(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    int cnt = 0;
    do {
        bool ok = true;
        for (int i = 0; i < 1; ++i) {
            int vmin = n, vmax = 0;
            for (int j = i; j < n; ++j) {
                vmin = min(vmin, a[j]);
                vmax = max(vmax, a[j]);
                if (vmax - vmin == j - i && j > i && j - i != n - 1) {
                    ok = false;
                }
            }
        }
        cnt += ok;
    } while (next_permutation(a.begin(), a.end()));
    cerr << cnt << endl;
    return cnt;
}

int test(int n, pair<int, int> v = {1000, 1000}) {
    // int n = 6;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    int cnt = 0;
    do {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int vmin = n, vmax = 0;
            for (int j = i; j < n; ++j) {
                vmin = min(vmin, a[j]);
                vmax = max(vmax, a[j]);
                if (make_pair(i + 1, j + 1) < v
                        && vmax - vmin == j - i && j > i && j - i != n - 1) {
                    ok = false;
                }
                if (make_pair(i + 1, j + 1) == v && vmax - vmin != j - i) {
                    ok = false;
                }
            }
        }
        cnt += ok;
    } while (next_permutation(a.begin(), a.end()));
    return cnt;
    // exit(0);
}

vector<int> solve(int n, const int MOD) {
    vector<int> noPrefix(n + 1);
    {
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> ndp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        noPrefix[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (auto& p: ndp) {
                memset(p.data(), 0, sizeof(int) * n);
            }
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                for (int k = j; k < n; ++k) {
                    ndp[j][k] = sum;
                    sum = (sum + dp[j][k]) % MOD;
                }
            }
            for (int k = 0; k < n; ++k) {
                int sum = 0;
                for (int j = k; j >= 0; --j) {
                    ndp[j][k] = (ndp[j][k] + sum) % MOD;
                    sum = (sum + dp[j][k]) % MOD;
                }
            }
            for (int j = 0; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    int v = (k - j + 1) - (i - 1);
                    if (v <= 0) continue;
                    ndp[j][k] = (ndp[j][k] + (int64_t) dp[j][k] * v) % MOD;
                }
            }
            noPrefix[i] = ndp[0][i - 1];
            for (int j = 0; j + i - 1 < n; ++j) {
                ndp[j][j + i - 1] = 0;
            }
            dp.swap(ndp);
        }
    }
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * (int64_t) i % MOD;
    }
    vector<int> vnoPrefix(n + 1);
    vnoPrefix[1] = 1;
    vnoPrefix[2] = 1;
    for (int i = 3; i <= n; ++i) {
        vnoPrefix[i] = fact[i - 1];
        for (int j = 2; j < i; ++j) {
            vnoPrefix[i] = (vnoPrefix[i] - vnoPrefix[j] * (int64_t) fact[i - j]) % MOD;
            vnoPrefix[i] = (vnoPrefix[i] + MOD) % MOD;
        }
    }
    // vector<vector<int>> comb(n + 1, vector<int>(n + 1, 0));
    // for (int i = 0; i <= n; ++i) {
    //     comb[i][0] = 1;
    //     for (int j = 1; j <= i; ++j) {
    //         comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    //     }
    // }
    
    vector<int> fans(n + 1, 1);
    vector<int> vfans(n + 1, 1);
    vfans[2] = 1;
    dp[1][1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        int sum = 0;
        for (int j = i - 1; j > 0; --j) {
            for (int k = i; k > j; --k) {
                if (j == 1 && k == i) {

                } else {
                    dp[i][j][k] = dp[i - (k - j)][j][j] * (int64_t) noPrefix[k - j + 1] % MOD;
                    if (false || (j == 2 && k == i)) {
                        dp[i][j][k] = (dp[i][j][k] -
                                2LL * vfans[i - (k - j)] * vnoPrefix[k - j + 1]) % MOD;
                        dp[i][j][k] = (dp[i][j][k] + MOD) % MOD;
                    }
                    sum = (sum + dp[i][j][k]) % MOD;
                }
            }
        }
        int v = (fact[i] - sum + MOD) % MOD;
        dp[i][i][i] = v;
        if (i == 8) {
            for (int j = i - 1; j > 0; --j) {
                for (int k = i; k > j; --k) {
                    if (j == 1 && k == i) {
                        continue;
                    }
                }
            }
        }
        for (int j = i; j > 0; --j) {
            for (int k = i; k > 0; --k) {
                dp[i][j][k] = (dp[i][j][k] + dp[i][j][k + 1]) % MOD;
                dp[i][j][k] = (dp[i][j][k] + dp[i][j + 1][k]) % MOD;
                dp[i][j][k] = (dp[i][j][k] - dp[i][j + 1][k + 1] + MOD) % MOD;
            }
        }
        fans[i] = dp[i][i][i];
        if (i > 2) {
            vfans[i] = (fans[i - 1] - vfans[i - 1] + MOD) % MOD;
        }
    }
    return fans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, Mod;
    cin >> t >> Mod;
    vector<int> dp = solve(400, Mod);

    while (t-- > 0) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}