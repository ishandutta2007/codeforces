#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        vector < int > a, b;
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            a.push_back(x);
        }
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (auto key : a) cout << key << " ";
        cout << '\n';
        for (auto key : b) cout << key << " ";
        cout << '\n';
    }
    return 0;
}