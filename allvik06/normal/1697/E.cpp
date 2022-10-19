#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
const int mod = 998244353;
const int INF = 1e9;
vector <vector <int>> g;

inline int dist(pair <int, int> a, pair <int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

vector <pair <int, int>> a;
vector <int> mn, cmp, st, used;

bool dfs(int v, int lvl) {
    st.push_back(v);
    used[v] = lvl;
    for (int i : g[v]) {
        if (mn[i] < mn[v]) return false;
        if (used[i] == lvl) continue;
        if (mn[i] == mn[v] && !dfs(i, lvl)) return false;
    }
    return true;
}

inline int power(int x, int b) {
    int cur = 1;
    while (b) {
        if (b & 1) {
            cur = (cur * x) % mod;
        }
        x = (x * x) % mod;
        b >>= 1;
    }
    return cur;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        int minn = INF;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            minn = min(minn, dist(a[i], a[j]));
        }
        for (int j = 0; j < n; ++j) {
            if (dist(a[i], a[j]) == minn) g[i].push_back(j);
        }
        mn.push_back(minn);
    }
    cmp.resize(n);
    used.resize(n, -1);
    int sum = 0;
    vector <int> all_sz;
    for (int i = 0; i < n; ++i) {
        if (cmp[i]) continue;
        if (dfs(i, i)) {
            bool ok = true;
            for (int j : st) {
                for (int j1 : st) {
                    if (j == j1) continue;
                    if (dist(a[j], a[j1]) != mn[i]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                for (int j : st) {
                    cmp[j] = 1;
                }
                all_sz.push_back((int)st.size());
                sum += (int)st.size();
            }
        }
        st.clear();
    }
    for (int i = 0; i < n - sum; ++i) all_sz.push_back(1);
    vector <vector <int>> dp((int)all_sz.size() + 1, vector <int> (n + 1));
    vector <int> fact(n + 1, 1), rfact(n + 1, 1);
    for (int i = 2; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
    rfact[n] = power(fact[n], mod - 2);
    for (int i = n - 1; i > 1; --i) rfact[i] = (rfact[i + 1] * (i + 1)) % mod;

    auto cnk = [&](int nn, int kk) {
        return (fact[nn] * rfact[kk] % mod) * rfact[nn - kk] % mod;
    };

    dp[0][0] = 1;
    for (int i = 0; i < (int)all_sz.size(); ++i) {
        if (all_sz[i] > 1) {
            for (int j = 0; j + all_sz[i] <= n; ++j) {
                dp[i + 1][j + all_sz[i]] = (dp[i + 1][j + all_sz[i]] + dp[i][j] * cnk(n - j, all_sz[i]) % mod * fact[all_sz[i]]) % mod;
            }
        }
        for (int j = 0; j < n; ++j) {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (n - j)) % mod;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) ans = (ans + dp[(int)all_sz.size()][i]) % mod;
    cout << ans;
}