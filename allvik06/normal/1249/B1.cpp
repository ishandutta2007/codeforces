#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int INF = 1e9;

signed main() {
    int q;
    cin >> q;
    for (int w = 0; w < q; ++w) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector <int> now(n);
        for (int i = 0; i < n; ++i) {
            now[i] = i;
        }
        vector <int> ans(n);
        for (int i = 1; i <= n; ++i) {
            vector <int> tmp(n);
            for (int j = 0; j < n; ++j) {
                tmp[a[j] - 1] = now[j];
            }
            now = tmp;
            for (int j = 0; j < n; ++j) {
                if (now[j] == j && ans[j] == 0) {
                    ans[j] = i;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}