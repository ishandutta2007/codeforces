#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

const int maxn = 2e5 + 5;

int cnt[maxn], cnt_nw[maxn];

vector<int> vv[maxn];

vector<pair<int, pair<int, int>>> g[maxn];

void dfs(int v, int pr) {
    for (auto [u, p] : g[v]) {
        if (u != pr) {
            for (auto vl : vv[p.second]) {
                cnt_nw[vl]--;
            }
            for (auto vl : vv[p.first]) {
                cnt_nw[vl]++;
                cnt[vl] = max(cnt[vl], cnt_nw[vl]);
            }
            dfs(u, v);
            for (auto vl : vv[p.second]) {
                cnt_nw[vl]++;
            }
            for (auto vl : vv[p.first]) {
                cnt_nw[vl]--;
            }
        }
    }
}

int ans = 0;

int _val[maxn];

void count_ans(int v, int pr, int val) {
    ans += val;
    if (ans >= mod) {
        ans -= mod;
    }
    for (auto [u, p] : g[v]) {
        if (u != pr) {
            int aans = val;
            for (auto vl : vv[p.second]) {
                aans = aans * 1LL * vl % mod;
            }
            for (auto vl : vv[p.first]) {
                aans = aans * 1LL * _val[vl] % mod;
            }
            count_ans(u, v, aans);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    ans = 0;
    for (int i = 0; i <= n; ++i) {
        g[i].clear();
        cnt[i] = cnt_nw[i] = 0;
    }
    for (int _ = 0; _ < n - 1; ++_) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        i--, j--;
        g[i].emplace_back(j, make_pair(x, y));
        g[j].emplace_back(i, make_pair(y, x));
    }
    dfs(0, 0);
    int kek = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            kek = kek * 1LL * i % mod;
        }
    }
    count_ans(0, 0, kek);
    cout << ans << '\n';
}

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < maxn; ++i) {
        int x = i;
        for (int j = 2; j * j <= x; ++j) {
            while (x % j == 0) {
                vv[i].push_back(j);
                x /= j;
            }
        }
        if (x > 1) {
            vv[i].push_back(x);
        }
        _val[i] = binpow(i, mod - 2);
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}