#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e10;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <pair <int, int>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        a.emplace_back(INF, 0);
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cur == a[i].second) {
                ++ans;
                continue;
            }
            int j = i;
            while (j < n) {
                if (abs(cur - a[i].second) <= a[j].first - a[i].first) {
                    break;
                } else {
                    if (cur >= a[i].second && cur >= a[j].second && a[i].second <= a[j].second) {
                        int kol = cur - a[j].second;
                        if (kol >= a[j].first - a[i].first && kol <= a[j + 1].first - a[i].first) ++ans;
                    } else if (cur <= a[i].second && cur <= a[j].second && a[i].second >= a[j].second) {
                        int kol = a[j].second - cur;
                        if (kol >= a[j].first - a[i].first && kol <= a[j + 1].first - a[i].first) ++ans;
                    }
                    ++j;
                }
            }
            cur = a[i].second;
            i = j - 1;
        }
        cout << ans << "\n";
    }
}