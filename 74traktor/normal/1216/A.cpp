#include <bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < (int)s.size(); i += 2) {
        if (s[i] == s[i - 1]) {
            s[i] = char('a' + ((s[i - 1] - 'a')^1));
            ans++;
        }
    }
    cout << ans << '\n';
    cout << s << '\n';
    return 0;
}