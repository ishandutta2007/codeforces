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
        int n, k;
        cin >> n >> k;
        vector <int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if (a.size() > k) {
            cout << -1 << "\n";
            continue;
        }
        cout << n * k << "\n";
        while(a.size() < k) a.push_back(1);
        for (int i = 0; i < n; ++i) {
            for (int j : a) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
}