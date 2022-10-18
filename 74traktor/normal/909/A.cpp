#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    string ans = s + t;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < (int)t.size(); ++j) {
            string w = "";
            for (int pos = 0; pos <= i; ++pos) w += s[pos];
            for (int pos = 0; pos <= j; ++pos) w += t[pos];
            ans = min(ans, w);
        }
    }
    cout << ans;
    return 0;
}