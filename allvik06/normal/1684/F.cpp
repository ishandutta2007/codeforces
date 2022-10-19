#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;
#define int long long
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        auto b = a;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        map <int, int> d;
        for (int i = 0; i < (int)b.size(); ++i) d[b[i]] = i;
        for (int& i : a) i = d[i];
        vector <vector <int>> all(n);
        for (int i = 0; i < n; ++i) {
            all[a[i]].push_back(i);
        }
        vector <pair <int, int>> seg(m);
        vector <vector <int>> open(n), close(n);
        for (int i = 0; i < m; ++i) {
            cin >> seg[i].first >> seg[i].second; --seg[i].first; --seg[i].second;
            open[seg[i].first].push_back(i);
            close[seg[i].second].push_back(i);
        }
        map <int, int> cur;
        multiset <int> s;
        int ll = -1;
        for (int i = 0; i < n; ++i) {
            for (int j : open[i]) {
                s.insert(i);
            }
            if (cur.count(a[i]) && !s.empty() && (*s.begin() <= cur[a[i]])) {
                ll = i;
                break;
            }
            cur[a[i]] = i;
            for (int j : close[i]) {
                s.erase(s.find(seg[j].first));
            }
        }
        cur.clear();
        s.clear();
        int r = -1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j : close[i]) {
                s.insert(i);
            }
            if (cur.count(a[i]) && !s.empty() && (*s.rbegin() >= cur[a[i]])) {
                r = i;
                break;
            }
            cur[a[i]] = i;
            for (int j : open[i]) {
                s.erase(s.find(seg[j].second));
            }
        }
        s.clear();
        int ans = INF;
        for (int l = 0; l < n; ++l) {
            if (l > 0) {
                for (int j : open[l - 1]) {
                    s.insert(seg[j].second);
                }
                if (!s.empty()) {
                    int cur_r = *s.rbegin(), x = a[l - 1];
                    int lb = 0, rb = (int)all[x].size();
                    while (rb - lb > 1) {
                        int mb = (lb + rb) / 2;
                        if (all[x][mb] <= cur_r) lb = mb;
                        else rb = mb;
                    }
                    r = max(r, all[x][lb]);
                }
            }
            if (r == -1) {
                ans = 0;
                break;
            }
            ans = min(ans, max(1LL, r - l + 1));
            if (ll == l) break;
        }
        cout << ans << "\n";
    }
    return 0;
}