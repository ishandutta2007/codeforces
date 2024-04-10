#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[30][30];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;
        vector<int> l(m), r(m);
        for (int i = 0; i < m; ++i)
            cin >> l[i] >> r[i];
        vector<pair<int, int>> used;
        for (int i = 0; i < m; ++i) {
            if (l[i] <= x && x <= r[i])
                used.push_back({ l[i], r[i] });
            else {
                for(int j = 0; j < used.size(); ++j)
                    if (!(l[i] > used[j].second||r[i] < used[j].first)) {
                        used.push_back({ l[i], r[i] });
                        break;
                    }
            }
        }
        sort(used.begin(), used.end());
        int ans = 1;
        int r1 = 0;
        for(int i = 0; i < used.size(); ++i)
            if (used[i].second > r1) {
                if (used[i].first > r1) {
                    ans += used[i].second - used[i].first + 1;
                    if (x >= used[i].first && x <= used[i].second)
                        ans--;
                }
                else {
                    ans += used[i].second - r1;
                    if (x > r1 && x <= used[i].second)
                        ans--;
                }
                r1 = used[i].second;
            }
        cout << ans << "\n";
    }
    return 0;
}