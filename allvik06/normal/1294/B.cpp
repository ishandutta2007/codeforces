#include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

signed main() {
    int t;
    cin >> t;
    ++t;
    while (--t) {
        int n;
        cin >> n;
        vector <pair <int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), cmp);
        int now = 0;
        pair <int, int> now1 = {0, 0};
        string s;
        while (now < n && now1.first <= 1000) {
            if (now1.first == a[now].first) {
                if (now1.second > a[now].second) {
                    break;
                }
                for (int i = now1.second; i < a[now].second; ++i) {
                    s += "U";
                }
                now1 = a[now];
                ++now;
            }
            else {
                s += "R";
                now1 = {now1.first + 1, now1.second};
            }
        }
        if (now == n) {
            cout << "YES\n" << s << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}