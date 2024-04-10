#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        int k1 = 0, k2 = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 1) {
                    k1++;
                    break;
                }
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                if (a[i][j] == 1) {
                    k2++;
                    break;
                }
        int k = min(n - k1, m - k2);
        if (k % 2 == 0)
            cout << "Vivek\n";
        else
            cout << "Ashish\n";
    }
    return 0;
}