#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n * 2);
        for (int i = 0; i < n * 2; ++i)
            cin >> a[i];
        vector<vector<int>> b(2);
        for (int i = 0; i < n * 2; ++i)
            b[a[i] % 2].push_back(i + 1);
        if (b[0].size() % 2 == 0) {
            for (int i = 2; i < b[0].size(); i += 2)
                cout << b[0][i] << ' ' << b[0][i + 1] << "\n";
            for (int i = 0; i < b[1].size(); i += 2) {
                if (b[0].size() == 0 && i == 0)
                    continue;
                cout << b[1][i] << ' ' << b[1][i + 1] << "\n";
            }
        }
        else {
            for (int i = 1; i < b[0].size(); i += 2)
                cout << b[0][i] << ' ' << b[0][i + 1] << "\n";
            for (int i = 1; i < b[1].size(); i += 2)
                cout << b[1][i] << ' ' << b[1][i + 1] << "\n";
        }
    }
    return 0;
}