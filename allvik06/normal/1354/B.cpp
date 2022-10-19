#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector <int> a = {-1, -1, -1};
        vector <vector <int>> bl(n, {-1, -1, -1});
        for (int i = 0; i < n; ++i) {
            a[s[i] - '1'] = i;
            bl[i] = a;
        }
        int minn = n + 1;
        for (int i = 0; i < n; ++i) {
            int pr = min(min(bl[i][0], bl[i][1]), bl[i][2]);
            if (pr == -1) continue;
            minn = min(i - pr + 1, minn);
        }
        if (minn == n + 1) minn = 0;
        cout << minn << "\n";
    }
}