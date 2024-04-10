#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i].first;
        bool f0 = false, f1 = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
            if (a[i].second == 0)
                f0 = true;
            else
                f1 = true;
        }
        if (f0 && f1)
            cout << "Yes\n";
        else {
            bool f = true;
            for (int i = 0; i < n - 1; ++i)
                if (a[i] > a[i + 1])
                    f = false;
            if (f)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}