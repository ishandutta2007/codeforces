#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (auto &c : a) {
            cin >> c;
        }
        int x = min(m - 1, k);
        int y = m - 1 - x;
        int ans = 0;
        for (int l = 0; l <= x; l++) {
            int r = x - l;
            int now = INF;
            for (int left = 0; left <= y; left++) {
                int right = y - left;
                now = min(now, max(a[l + left], a[n - 1 - r - right]));
            }
            ans = max(ans, now);
        }
        cout << ans << "\n";
    }
    return 0;
}