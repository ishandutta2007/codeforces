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
        int n, k, sum = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector <vector <int>> kol(k);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                kol[i % k].push_back(i);
                ++sum;
            }
        }
        if (sum == 0) {
            cout << 0 << "\n";
            continue;
        }
        int minn = sum;
        for (int i = 0; i < k; ++i) {
            int last1 = 0, last2 = 1;
            for (int j = 1; j < kol[i].size(); ++j) {
                last1 = min(last1 + (kol[i][j] - kol[i][j - 1]) / k - 1, last2);
                ++last2;
                minn = min(minn, sum + min(last1, last2) - j - 1);
            }
            minn = min(minn, sum + min(last1, last2) - (int)kol[i].size());
        }
        cout << minn << "\n";
    }
}