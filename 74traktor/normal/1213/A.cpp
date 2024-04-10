#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x % 2 == 0) ans1++;
        else ans2++;
    }
    /*vector < int > a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = 1e18;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if ((a[j] - a[i]) % 2 != 0) sum++;
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';*/
    cout << min(ans1, ans2) << '\n';
    return 0;
}