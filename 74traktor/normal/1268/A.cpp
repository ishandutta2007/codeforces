#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s, s1;
    cin >> s;
    for (int j = 0; j < k; ++j) s1 += s[j];
    string s2;
    while ((int)s2.size() < (int)s.size()) s2 += s1;
    string t = "";
    for (int j = 0; j < (int)s.size(); ++j) t += s2[j];
    if (t >= s) {
        cout << t.size() << '\n';
        cout << t << '\n';
        return 0;
    }
    for (int j = (int)s1.size() - 1; j >= 0; --j) {
        if (s1[j] != '9') {
            s1[j] = char(s1[j] - '0' + 1 + '0');
            for (int z = j + 1; z < (int)s1.size(); ++z) s1[z] = '0';
            break;
        }
    }
    string ans = "";
    while ((int)ans.size() < (int)s.size()) ans += s1;
    cout << (int)s.size() << '\n';
    for (int i = 0; i < (int)s.size(); ++i) cout << ans[i];
    return 0;
}