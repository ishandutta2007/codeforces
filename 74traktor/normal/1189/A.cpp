#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (auto c : s) {
        if (c == '0') x++;
        else y++;
    }
    if (x != y) {
        cout << 1 << '\n';
        cout << s << '\n';
    }
    else {
        cout << 2 << '\n';
        cout << s[0] << " ";
        for (int i = 1; i < n; ++i) cout << s[i];
    }
    return 0;
}