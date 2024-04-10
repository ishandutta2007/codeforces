#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector <int> now;
    for (int i = 2; i <= 1000; ++i) {
        bool flag = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            now.push_back(i);
        }
        if (now.size() == 11) {
            break;
        }
    }
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector <int> ans(n);
        int last = 1;
        for (int i = 0; i < 11; ++i) {
            bool flag = false;
            for (int j = 0; j < n; ++j) {
                if (a[j] % now[i] == 0 && ans[j] == 0) {
                    flag = true;
                    ans[j] = last;
                }
            }
            if (flag) {
                ++last;
            }
        }
        cout << last - 1 << "\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}