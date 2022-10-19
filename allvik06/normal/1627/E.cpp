#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
#define int long long
const int INF = 1e18;

inline int ind(vector <int>& a, int x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vector <vector <int>> all(n);
    vector <vector <array <int, 4>>> nxt(n);
    for (int i = 0; i < k; ++i) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h; --a; --c;
        nxt[a].push_back({b, c, d, h});
        all[a].push_back(b);
        all[c].push_back(d);
    }
    all[0].push_back(1);
    all[n - 1].push_back(m);
    for (int i = 0; i < n; ++i) {
        sort(all[i].begin(), all[i].end());
        all[i].resize(unique(all[i].begin(), all[i].end()) - all[i].begin());
    }
    vector <vector <int>> dp(n);
    for (int i = 0; i < n; ++i) dp[i].resize((int)all[i].size(), -INF);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < (int)all[i].size(); ++j) {
            if (dp[i][j - 1] == -INF) continue;
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - (all[i][j] - all[i][j - 1]) * x[i]);
        }
        for (int j = (int)all[i].size() - 2; j >= 0; --j) {
            if (dp[i][j + 1] == -INF) continue;
            dp[i][j] = max(dp[i][j], dp[i][j + 1] - (all[i][j + 1] - all[i][j]) * x[i]);
        }
        for (auto j : nxt[i]) {
            int from = ind(all[i], j[0]);
            int to = ind(all[j[1]], j[2]);
            if (dp[i][from] == -INF) continue;
            dp[j[1]][to] = max(dp[j[1]][to], dp[i][from] + j[3]);
        }
    }
    if (dp[n - 1].back() == -INF) cout << "NO ESCAPE\n";
    else cout << -dp[n - 1].back() << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */