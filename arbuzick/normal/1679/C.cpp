#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> s1, s2;
    vector<int> cnt1(n), cnt2(n);
    for (int i = 0; i < n; ++i) {
        s1.insert(i);
        s2.insert(i);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            cnt1[x]++;
            cnt2[y]++;
            if (cnt1[x] == 1) {
                s1.erase(x);
            }
            if (cnt2[y] == 1) {
                s2.erase(y);
            }
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            cnt1[x]--;
            cnt2[y]--;
            if (cnt1[x] == 0) {
                s1.insert(x);
            }
            if (cnt2[y] == 0) {
                s2.insert(y);
            }
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--;
            if ((s1.lower_bound(x1) != s1.end() && *s1.lower_bound(x1) < x2) && (s2.lower_bound(y1) != s2.end() && *s2.lower_bound(y1) < y2)) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
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