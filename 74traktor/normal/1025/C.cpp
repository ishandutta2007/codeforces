#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    s = s + s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        int j = i + 1;
        while (j < (int)s.size() && s[j] != s[j - 1]) ++j;
        ans = max(ans, j - i);
        i = j - 1;
    }
    cout << min(ans, (int)s.size() / 2) << '\n';
    return 0;
}