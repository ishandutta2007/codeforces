#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int maxx = 1, now = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) ++now;
            else now = 1;
            if (now > maxx) {
                maxx = now;
            }
        }
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if (a.size() > maxx) {
            cout << maxx << "\n";
        }
        else if (maxx == a.size()) {
            cout << maxx - 1 << "\n";
        }
        else {
            cout << a.size() << "\n";
        }
    }
}