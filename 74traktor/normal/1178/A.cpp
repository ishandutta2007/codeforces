#include <bits/stdc++.h>

using namespace std;

int a[105];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int t = 0, s = 0;
    for (int i = 1; i <= n; ++i) {
        t += a[i];
    }
    vector < int > ans = {1};
    for (int i = 2; i <= n; ++i) {
        if (a[i] * 2 <= a[1]) {
            s += a[i];
            ans.push_back(i);
        }
    }
    s += a[1];
    if (2 * s > t) {
        cout << (int)ans.size() << '\n';
        for (auto key : ans) cout << key << " ";
    }
    else cout << 0 << '\n';
    return 0;
}