#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y, c;
    point() {
        x = y = c = 0;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].c;
        a[i].c--;
    }
    auto cmp = [&](point a, point b, int i) {
        if (i == 0) {
            return a.x < b.x;
        } else if (i == 1) {
            return a.y < b.y;
        } else if (i == 2) {
            return a.x > b.x;
        } else {
            return a.y > b.y;
        }
    };
    vector<vector<point>> sorted(4);
    for (int i = 0; i < 4; ++i) {
        sorted[i] = a;
        sort(sorted[i].begin(), sorted[i].end(), [&](point a, point b) { return cmp(a, b, i); });
    }
    int l = 0, r = n / 3 + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        bool ch = false;
        for (int col = 0; col < 3; ++col) {
            for (int t = 0; t < 4; ++t) {
                point p;
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (sorted[t][i].c == col) {
                        cnt++;
                        if (cnt == m) {
                            p = sorted[t][i];
                            break;
                        }
                    }
                }
                for (int t2 = 0; t2 < 4; ++t2) {
                    int cnt2 = 0;
                    point p2;
                    for (int i = 0; i < n; ++i) {
                        if (sorted[t2][i].c == (col + 1) % 3 && cmp(p, sorted[t2][i], t)) {
                            cnt2++;
                            if (cnt2 == m) {
                                p2 = sorted[t2][i];
                                break;
                            }
                        }
                    }
                    if (cnt2 < m) {
                        continue;
                    }
                    int cnt3 = 0;
                    for (int i = 0; i < n; ++i) {
                        if ((sorted[t2][i].c + 1) % 3 == col && cmp(p, sorted[t2][i], t) && cmp(p2, sorted[t2][i], t2)) {
                            cnt3++;
                        }
                    }
                    if (cnt3 >= m) {
                        ch = true;
                    }
                }
            }
        }
        if (ch) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l * 3 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}