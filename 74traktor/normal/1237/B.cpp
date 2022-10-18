#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn];
int b[maxn];
int pos[maxn];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        pos[a[i]] = i;
    }
    int imin = n + 7;
    for (int i = n; i >= 1; --i) {
        if (pos[b[i]] > imin) ans++;
        imin = min(imin, pos[b[i]]);
    }
    cout << ans << '\n';
    return 0;
}