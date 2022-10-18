#include<bits/stdc++.h>

using namespace std;

#define int long long
int a[200005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif// HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n > m) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) ans = abs(a[i] - a[j]) * ans % m;
    }
    cout << ans << '\n';
    return 0;
}