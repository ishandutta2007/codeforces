#include <bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 2e5 + 5;
int pref[maxn];
int suff[maxn][2];
int a[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if (a[i] < 0) pref[i] = pref[i] + 1;
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= 1; ++j) suff[i][j] = suff[i + 1][j];
        suff[i][pref[i] % 2]++;
    }
    for (int i = 1; i <= n; ++i) {
        int x = pref[i - 1] % 2;
        ans += suff[i][x];
    }
    cout << n * (n - 1) / 2 + n - ans << " " << ans << '\n';
    return 0;
}