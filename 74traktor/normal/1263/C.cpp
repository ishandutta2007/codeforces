#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    set < int > ans = {0};
    for (int x = 1; x <= 40000; ++x) {
        ans.insert(n / x);
    }
    for (int x = 1; x <= 40000; ++x) {
        int k = n / x;
        if (k != 0 && n / k == x) ans.insert(x);
    }
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key << " ";
    cout << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}