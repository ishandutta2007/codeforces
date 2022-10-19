#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

inline int get_mex(int n, vector <int>& a) {
    vector <int> all(n + 1);
    for (int i : a) ++all[i];
    for (int i = 0; i <= n; ++i) {
        if (all[i] == 0) return i;
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), ans;
        for (int i = 0; i < n; ++i) cin >> a[i];
        while (get_mex(n, a) < n) {
            int mex = get_mex(n, a);
            ans.push_back(mex);
            a[mex] = mex;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == i) continue;
            int cur = a[i];
            ans.push_back(i);
            a[i] = get_mex(n, a);
            while (true) {
                int n_cur = a[cur];
                ans.push_back(cur);
                a[cur] = get_mex(n, a);
                if (cur == i) break;
                cur = n_cur;
            }
        }
        cout << (int)ans.size() << "\n";
        for (int i : ans) cout << i + 1 << " ";
        cout << "\n";
    }
}