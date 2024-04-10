#include<bits/stdc++.h>

using namespace std;

int pref[2][1005], suff[2][1005];

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
        string s;
        cin >> s;
        int ans = (int)s.size();
        for (int i = 0; i <= (int)s.size(); ++i) pref[0][i] = 0, suff[0][i] = 0, pref[1][i] = 0, suff[1][i] = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            for (int j = 0; j <= 1; ++j) {
                pref[j][i] = pref[j][max(0, i - 1)];
            }
            pref[s[i] - '0'][i]++;
        }
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            for (int j = 0; j <= 1; ++j) {
                suff[j][i] = suff[j][i + 1];
            }
            suff[s[i] - '0'][i]++;
        }
        for (int i = 0; i < (int)s.size(); ++i) {
            ans = min({ans, pref[1][i] + suff[0][i + 1], pref[0][i] + suff[1][i + 1]});
        }
        cout << ans << '\n';
    }
    return 0;
}