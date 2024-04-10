#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(m);
    for (auto &e : a) cin >> e.first >> e.second, e.first--, e.second--;
    sort(a.begin(), a.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.first + lhs.second < rhs.first + rhs.second;
    });
    vector<int> suff(m + 1, 0);
    for (int i = 0; i <= n - k; i++) {
        int cur = 0;
        for (int j = m - 1; j >= 0; j--) {
            cur += max(0, min(a[j].second, i + k - 1) - max(a[j].first, i) + 1);
            suff[j] = max(suff[j], cur);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n - k; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            cur += max(0, min(a[j].second, i + k - 1) - max(a[j].first, i) + 1);
            ans = max(ans, cur + suff[j + 1]);
        }
    }
    cout << ans << '\n';

    return 0;
}