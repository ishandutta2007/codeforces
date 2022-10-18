#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
int a[maxn], b[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p, ans = 0;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] % p == 0) ans++;
        else break;
    }
    for (int i = 0; i < m; ++i) {
        if (b[i] % p == 0) ans++;
        else break;
    }
    cout << ans << '\n';
    return 0;
}