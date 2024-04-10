#include <bits/stdc++.h>

using namespace std;

#define int long long

#define x first
#define y second

int intersect(int l1, int r1, int l2, int r2) {
    return max((long long)0, min(r1,r2) - max(l1, l2) + 1);
}

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> ps(m);
    for (int i = 0; i < m; ++i) {
        cin >> ps[i].x >> ps[i].y;
        ps[i].x--;
        ps[i].y--;
    }
    int fans = 0;
    for (int i = 0; i <= n - k; ++i) {
        int ans = 0;
        vector<int> d(5 * n + 20);
        for (auto p : ps) {
            int len = intersect(i, i + k - 1, p.x, p.y);
            // cout << "LEN -> " << len << endl;
            ans += len;
            if (len < k && len < p.y - p.x + 1) {
                d[p.x - k + 1 + len + 2 * n + 10] += 1;
                d[p.x + 1 + 2 * n + 10] -= 1;
                d[p.y + 2 - k + 2 * n + 10] -= 1;
                d[p.y + 2 - len + 2 * n + 10] += 1;
            }
        }
        // cout << ans << endl;
        // cout << "=====" << endl;
        int maxx = 0;
        int dd = 0;
        int cur = 0;
        for (int i = 0; i < 5 * n + 20; ++i) {
            dd += d[i];
            cur += dd;
            if (i >= 2 * n + 10 && i <= 3 * n - k + 10)
                maxx = max(maxx, cur);
        }
        fans = max(fans, ans + maxx);
    }
    cout << fans << endl;
}