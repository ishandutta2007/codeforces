#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) {
            cin >> e;
        }
        int mx = 1;
        for (int i = 0; i < n; i++) {
            int tmp = 2;
            int r = n - 1;
            while (a[r] > a[i]) {
                int tar = (a[r] + a[i]) / 2;
                int id = upper_bound(a.begin(), a.end(), tar) - a.begin() - 1;
                r = id;
                tmp++;
            }
            tmp += r - i - 1;
            mx = max(mx, tmp);
        }
        cout << n - mx << '\n';
    }
    
    return 0;
}