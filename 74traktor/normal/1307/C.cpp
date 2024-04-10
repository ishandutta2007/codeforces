#include<bits/stdc++.h>

using namespace std;

#define int long long
int cnt[27];
int answ[27][27];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            answ[j][s[i] - 'a'] += cnt[j];
        }
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        ans = max(ans, cnt[i]);
        for (int j = 0; j < 26; ++j) ans = max(ans, answ[i][j]);
    }
    cout << ans << '\n';
    return 0;
}