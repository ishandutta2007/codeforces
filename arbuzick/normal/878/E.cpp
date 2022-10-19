#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int binpow(int n, int k) {
    if (k == 0) {
        return 1;
    }
    if (k % 2) {
        return binpow(n, k - 1) * 1LL * n % mod;
    }
    int m = binpow(n, k / 2);
    return m * 1LL * m % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pow(n + 1), _pow(n + 1);
    pow[0] = _pow[0] = 1;
    for (int i = 0; i < n; ++i) {
        pow[i + 1] = pow[i] * 2 % mod;
        _pow[i + 1] = binpow(pow[i + 1], mod - 2);
    }
    vector<int> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = (pr[i] + a[i] * 1LL * pow[i]) % mod;
    }
    vector<int> nxt(n), fn(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            nxt[i] = -1;
            fn[i] = a[i];
        } else {
            if (a[i] < 0) {
                nxt[i] = i - 1;
                fn[i] = a[i];
            } else {
                nxt[i] = nxt[i - 1];
                fn[i] = fn[i - 1];
                if (a[i] == 0 || nxt[i] == -1) {
                    continue;
                }
                if (i - nxt[i] - 1 > 30 || a[i] * 1LL * (1 << (i - nxt[i] - 1)) >= mod * 2 + 1) {
                    fn[i] = mod * 2 + 1;
                } else {
                    fn[i] = fn[i] + a[i] * 1LL * (1 << (i - nxt[i] - 1));
                }
                while (nxt[i] >= 0) {
                    if (fn[i] < 0) {
                        break;
                    }
                    if (fn[i] == mod * 2 + 1) {
                        nxt[i] = -1;
                    } else {
                        if (fn[i] == 0) {
                            fn[i] = fn[nxt[i]];
                        } else if (nxt[i] - nxt[nxt[i]] > 30 || fn[nxt[i]] + fn[i] * 1LL * (1 << (nxt[i] - nxt[nxt[i]])) >= mod * 2 + 1) {
                            fn[i] = mod * 2 + 1;
                        } else {
                            fn[i] = fn[nxt[i]] + fn[i] * 1LL * (1 << (nxt[i] - nxt[nxt[i]]));
                        }
                        nxt[i] = nxt[nxt[i]];
                    }
                }
            }
        }
    }
    int lg = 20;
    vector<vector<int>> go(lg, vector<int>(n)), sum(lg, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        go[0][i] = nxt[i];
        sum[0][i] = ((pr[i + 1] - pr[nxt[i] + 1]) * 1LL * _pow[nxt[i]] % mod + mod) % mod;
    }
    for (int i = 1; i < lg; ++i) {
        for (int j = 0; j < n; ++j) {
            if (go[i - 1][j] == -1 || go[i - 1][go[i - 1][j]] == -1) {
                go[i][j] = -1;
                continue;
            }
            go[i][j] = go[i - 1][go[i - 1][j]];
            sum[i][j] = (sum[i - 1][j] + sum[i - 1][go[i - 1][j]]) % mod;
        }
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 0;
        int pos = r;
        for (int j = lg - 1; j >= 0; --j) {
            if (go[j][pos] > l - 1) {
                ans = (ans + sum[j][pos]) % mod;
                pos = go[j][pos];
            }
        }
        assert(nxt[pos] <= l - 1);
        int nx = l - 1;
        ans = ((ans + (pr[pos + 1] - pr[nx + 1]) * 1LL * _pow[nx + 1] % mod) % mod + mod) % mod;
        // while (pos >= l) {
        //     int nx = max(nxt[pos], l - 1);
        //     if (nx == l - 1) {
        //         // cout << pos << ' ' << nx << ' ' << mod + (pr[pos + 1] - pr[nx + 1]) *_pow[1] % mod << '\n';
        //         ans = ((ans + (pr[pos + 1] - pr[nx + 1]) * 1LL * _pow[nx + 1] % mod) % mod + mod) % mod;
        //     } else {
        //         ans = ((ans + (pr[pos + 1] - pr[nx + 1]) * 1LL * _pow[nx] % mod) % mod + mod) % mod;
        //     }
        //     pos = nx;
        // }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}