#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e10;

struct event {
    int x, ind;
    bool point, open;

    event() {}

    event(int x, int ind, bool point, bool open) : x(x), ind(ind), point(point), open(open) {}
};

bool cmp(event a, event b) {
    if (a.x != b.x) return a.x < b.x;
    return a.point < b.point;
}

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<pair<int, int>> b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i].first >> b[i].second;
        sort(a.begin(), a.end());
        vector<event> all;
        vector<bool> used(m);
        for (int i = 0; i < n; ++i) {
            all.emplace_back(a[i], 0, true, false);
        }
        for (int i = 0; i < m; ++i) {
            all.emplace_back(b[i].first, i, false, true);
            all.emplace_back(b[i].second + 1, i, false, false);
        }
        sort(all.begin(), all.end(), cmp);
        set<int> cur;
        for (int i = 0; i < 2 * m + n; ++i) {
            if (all[i].open) cur.insert(all[i].ind);
            else if (all[i].point) {
                while (!cur.empty()) {
                    used[*cur.begin()] = true;
                    cur.erase(cur.begin());
                }
            } else cur.erase(all[i].ind);
        }
        vector<pair<int, int>> seg;
        for (int i = 0; i < m; ++i) {
            if (!used[i]) seg.push_back(b[i]);
        }
        sort(seg.begin(), seg.end());
        vector<int> flex((int) seg.size());
        vector<pair<int, int>> dp(n, make_pair(INF, INF));
        int kol_less = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                int minn = a[i];
                for (auto j : seg) {
                    if (j.second > a[i]) break;
                    minn = min(minn, j.second);
                    ++kol_less;
                }
                dp[i].first = a[i] - minn;
                dp[i].second = (a[i] - minn) * 2;
                continue;
            }
            int now_kol = 0;
            for (int j = kol_less; j < (int) seg.size(); ++j) {
                if (seg[j].second < a[i]) ++now_kol;
                else break;
            }
            if (now_kol == 0) {
                dp[i].first = dp[i].second = dp[i - 1].first;
                continue;
            }
            flex[kol_less + now_kol - 1] = seg[kol_less + now_kol - 1].second;
            for (int j = kol_less + now_kol - 2; j >= kol_less; --j) {
                flex[j] = min(flex[j + 1], seg[j].second);
            }
            for (int j = 1; j < now_kol; ++j) {
                dp[i].first = min(dp[i].first, dp[i - 1].second + seg[kol_less + j - 1].first - a[i - 1] + a[i] -
                                               flex[kol_less + j]);
                dp[i].second = min(dp[i].second, dp[i - 1].second + seg[kol_less + j - 1].first - a[i - 1] +
                                                2 * (a[i] - flex[kol_less + j]));
                dp[i].first = min(dp[i].first, dp[i - 1].first + 2 * (seg[kol_less + j - 1].first - a[i - 1]) + a[i] -
                                               flex[kol_less + j]);
                dp[i].second = min(dp[i].second, dp[i - 1].first + 2 * (seg[kol_less + j - 1].first - a[i - 1]) +
                                                 2 * (a[i] - flex[kol_less + j]));
            }
            dp[i].first = min(dp[i].first, a[i] - flex[kol_less] + dp[i - 1].first);
            dp[i].second = min(dp[i].second, 2 * (a[i] - flex[kol_less]) + dp[i - 1].first);
            dp[i].first = min(dp[i].first, dp[i - 1].second + seg[kol_less + now_kol - 1].first - a[i - 1]);
            dp[i].second = min(dp[i].second, dp[i - 1].second + seg[kol_less + now_kol - 1].first - a[i - 1]);
            dp[i].first = min(dp[i].first, dp[i - 1].first + 2 * (seg[kol_less + now_kol - 1].first - a[i - 1]));
            dp[i].second = min(dp[i].second, dp[i - 1].first + 2 * (seg[kol_less + now_kol - 1].first - a[i - 1]));
            kol_less += now_kol;
        }
        if (kol_less == (int) seg.size()) cout << dp.back().first << "\n";
        else {
            cout << min(dp.back().second + seg.back().first - a.back(), dp.back().first + 2 * (seg.back().first - a.back())) << "\n";
        }
    }
}