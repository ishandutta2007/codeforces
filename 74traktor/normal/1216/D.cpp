#include <bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        int x = a % b;
        a = b, b = x;
    }
    return a + b;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, imax = 0, ans = 0;
    cin >> n;
    vector < int > a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        imax = max(imax, x);
        a.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        ans = gcd(ans, imax - a[i]);
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) cur += (imax - a[i]) / ans;
    cout << cur << " " << ans << '\n';
    return 0;
}