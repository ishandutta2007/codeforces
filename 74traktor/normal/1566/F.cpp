#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
vector < int > L[maxn], R[maxn];
vector < int > dp[maxn];
int inf = 1e15 + 7;
int a[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, l, r;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            L[i] = {}, R[i] = {}, dp[i] = {};
        }
        sort(a + 1, a + n + 1);
        vector < pair < int, int > > go;
        for (int i = 1; i <= m; ++i) {
            cin >> l >> r;
            go.push_back({l, r});
        }
        sort(go.begin(), go.end(), [](pair < int, int > f, pair < int, int > s) {
            if (f.first != s.first) return f.first < s.first;
            return f.second > s.second;
        });
        vector < pair < int, int > > ans;
        for (auto key : go) {
            while ((int)ans.size() > 0 && ans.back().second > key.second) ans.pop_back();
            ans.push_back(key);
        }
        vector < pair < int, int > > tmp;
        for (auto key : ans) {
            int l = lower_bound(a + 1, a + n + 1, key.first) - a;
            int r = upper_bound(a + 1, a + n + 1, key.second) - a;
            if (l == r) tmp.push_back(key);
        }
        int ptr = 0;
        for (int i = 1; i <= n; ++i) {
            while (ptr < (int)tmp.size() && tmp[ptr].second < a[i]) {
                L[i].push_back(ptr++);
            }
        }
        ptr = (int)tmp.size() - 1;
        for (int i = n; i >= 1; --i) {
            while (ptr >= 0 && tmp[ptr].first > a[i]) {
                R[i].push_back(ptr--);
            }
            reverse(R[i].begin(), R[i].end());
        }
        for (int i = 1; i <= n; ++i) {
            dp[i].resize(R[i].size() + 1, inf);
        }
        for (int i = 0; i <= (int)R[1].size(); ++i) {
            int lef, now = a[1], righ;
            if ((int)L[1].size() == 0) lef = a[1];
            else lef = tmp[0].second;
            if (i == 0) righ = a[1];
            else righ = tmp[R[1][i - 1]].first;
            dp[1][i] = righ - lef + min(now - lef, righ - now);
        }
        for (int i = 2; i <= n; ++i) {
            int one = inf, two = inf;
            for (int j = 0; j <= (int)R[i - 1].size(); ++j) {
                int pos = a[i];
                if (j != (int)R[i - 1].size()) pos = tmp[R[i - 1][j]].second;
                one = min(one, a[i] - pos + dp[i - 1][j]);
                two = min(two, 2 * (a[i] - pos) + dp[i - 1][j]);
            }
            for (int j = 0; j <= (int)R[i].size(); ++j) {
                int righ = a[i];
                if (j != 0) righ = tmp[R[i][j - 1]].first;
                dp[i][j] = min(one + 2 * (righ - a[i]), two + righ - a[i]);
            }
        }
        cout << dp[n][R[n].size()] << '\n';
    }
    return 0;
}