#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map <pair <int, int>, vector <int>> a;
        set <pair <int, int>> b;
        pair <int, int> now = {0, 0};
        a[{0, 0}].push_back(0);
        b.insert({0, 0});
        int cur = 1;
        for (int i : s) {
            if (i == 'L') {
                now = {now.first - 1, now.second};
            }
            else if (i == 'R') {
                now = {now.first + 1, now.second};
            }
            else if (i == 'U') {
                now = {now.first, now.second + 1};
            }
            else {
                now = {now.first, now.second - 1};
            }
            a[now].push_back(cur);
            ++cur;
            b.insert(now);
        }
        int ans = 10000000;
        pair <int, int> res;
        for (auto i : b) {
            int len = a[i].size();
            for (int j = 1; j < len; ++j) {
                if (a[i][j] - a[i][j - 1] < ans) {
                    ans = a[i][j] - a[i][j - 1];
                    res = {a[i][j - 1], a[i][j]};
                }
            }
        }
        if (ans == 10000000) {
            cout << -1 << "\n";
        }
        else {
            cout << res.first + 1 << " " << res.second << "\n";
        }
    }
    return 0;
}