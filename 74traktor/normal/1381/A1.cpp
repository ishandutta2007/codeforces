#include<bits/stdc++.h>

using namespace std;

inline void f(string &s, int x) {
    for (int i = 0; i < x; ++i) {
        if (s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
    for (int i = 0; i < x / 2; ++i) swap(s[i], s[x - i - 1]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> n;
        cin >> a >> b;
        vector < int > ans;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == b[i]) continue;
            if (a[0] != b[i]) {
                ans.push_back(i + 1);
                f(a, i + 1);
            }
            else {
                ans.push_back(1);
                f(a, 1);
                ans.push_back(i + 1);
                f(a, i + 1);
            }
        }
        cout << ans.size() << " ";
        for (auto key : ans) cout << key << " ";
        cout << '\n';
    }
    return 0;
}