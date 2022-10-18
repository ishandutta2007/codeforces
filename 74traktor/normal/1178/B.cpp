#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = 0, cnt1 = 0, cnt2 = 0;
    int n = (int)s.size();
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'v' && s[i + 1] == 'v') cnt2++;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') {
            ans += cnt1 * cnt2;
        }
        else {
            if (i > 0 && s[i - 1] == 'v') cnt2--, cnt1++;
        }
    }
    cout << ans << '\n';
    return 0;
}