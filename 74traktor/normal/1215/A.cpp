#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int x = a1 * (k1 - 1) + a2 * (k2 - 1);
    int sum = a1 + a2;
    if (k1 > k2) swap(k1, k2), swap(a1, a2);
    int t = n / k1;
    if (t > a1) {
        sum -= a1;
        sum -= min(a2, (n - k1 * a1) / k2);
    }
    else {
        sum -= t;
    }
    if (x >= n) cout << 0;
    else cout << min(a1 + a2, n - x);
    cout << " " << a1 + a2 - sum << '\n';
    return 0;
}