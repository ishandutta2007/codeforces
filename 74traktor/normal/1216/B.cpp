#include <bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < pair < int, int > > a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += i * a[i].first + 1;
    cout << ans << '\n';
    for (auto key : a) cout << key.second << " ";
    return 0;
}