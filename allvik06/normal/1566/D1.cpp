#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;

inline int upd_mask(int mask, char c1, char c2) {
    return (mask | (1 << (c1 - '0')) | (1 << (c2 - '0')));
}

inline int get_cal(int mask) {
    if (mask == 3) return 2;
    if (mask & 1) return 1;
    return 0;
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
        int n, m;
        cin >> n >> m;
        vector <int> a(m);
        for (int i = 0; i < m; ++i) cin >> a[i];
        vector <pair <int, int>> all;
        for (int i = 0; i < m; ++i) all.emplace_back(a[i], -i);
        sort(all.begin(), all.end());
        vector <int> pl(m);
        for (int i = 0; i < m; ++i) {
            pl[-all[i].second] = i;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                ans += (pl[j] < pl[i]);
            }
        }
        cout << ans << "\n";
    }
}