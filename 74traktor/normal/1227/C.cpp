#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    string s;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        vector < pair < int, int > > ans;
        for (int i = 0; i < n; ++i) {
            char T;
            if (i < 2 * (k - 1)) {
                if (i % 2 == 0) T = '(';
                else T = ')';
            }
            else {
                if (i < n / 2 + k - 1) T = '(';
                else T = ')';
            }
            int pos;
            for (int j = i; j < (int)s.size(); ++j) {
                if (s[j] == T) {
                    pos = j;
                    break;
                }
            }
            ans.push_back({i + 1, pos + 1});
            for (int j = i; j <= (i + pos) / 2; ++j) {
                swap(s[j], s[pos - (j - i)]);
            }
        }
        cout << ans.size() << '\n';
        for (auto key : ans) cout << key.first << " " << key.second << '\n';
    }
    return 0;
}