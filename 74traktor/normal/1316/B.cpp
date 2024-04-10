#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = s;
        int pos = 1;
        for (int k = 2; k <= n; ++k) {
            string d = "";
            for (int j = k - 1; j < n; ++j) d += s[j];
            if ((n - k + 1) % 2 == 0) for (int j = 0; j < k - 1; ++j) d += s[j];
            else for (int j = k - 2; j >= 0; --j) d += s[j];
            if (d < ans) {
                ans = min(ans, d);
                pos = k;
            }
        }
        cout << ans << '\n';
        cout << pos << '\n';
    }
    return 0;
}