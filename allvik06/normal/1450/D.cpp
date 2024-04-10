#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            deque<int> cur;
            vector <bool> cha(n + 1);
            for (int i = 0; i < m; ++i) {
                while (!cur.empty() && a[cur.back()] >= a[i]) cur.pop_back();
                cur.push_back(i);
            }
            cha[a[cur.front()]] = true;
            bool f = false;
            for (int i = m; i < n; ++i) {
                while (!cur.empty() && a[cur.back()] >= a[i]) cur.pop_back();
                cur.push_back(i);
                if (cur.front() == i - m) cur.pop_front();
                if (cha[a[cur.front()]]) {
                    f = true;
                    break;
                }
                cha[a[cur.front()]] = true;
            }
            for (int i = n - m + 2; i <= n; ++i) {
                if (cha[i]) f = true;
            }
            if (!f) r = m;
            else l = m;
        }
        vector <int> ans(n + 1);
        for (int i = r; i <= n; ++i) ans[i] = 1;
        vector <bool> cha(n + 1);
        bool f = false;
        for (int i : a) {
            if (cha[i]) f = true;
            cha[i] = true;
        }
        if (!f) ans[1] = 1;
        for (int i = 1; i <= n; ++i) cout << ans[i];
        cout << "\n";
    }
}