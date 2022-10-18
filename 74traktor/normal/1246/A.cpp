#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;
    for (int ans = 1; ans <= 1000000; ++ans) {
        int x = n - ans * p, f = 0;
        if (x <= 0) continue;
        int sum = 0;
        for (int j = 0; j <= 60; ++j) {
            if ((x&(1ll << j)) > 0) sum++;
        }
        if (sum <= ans && ans <= x) {
            cout << ans << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}