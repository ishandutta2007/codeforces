#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[1005][1005];
int ans[1005];
int n;

int gcd(int x, int y) {
    while (x > 0 && y > 0) {
        int t = x % y;
        x = y, y = t;
    }
    return x + y;
}

void check(int x) {
    ans[1] = x;
    for (int i = 2; i <= n; ++i) {
        ans[i] = a[1][i] / x;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i][j] != ans[i] * ans[j]) {
                return;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    exit(0);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    for (int i = 1; i * i <= a[1][2]; ++i) {
        if (a[1][2] % i == 0) {
            int x1 = i, x2 = a[1][2] / i;
            if (a[1][3] * x2 == a[2][3] * x1 && a[1][3] % x1 == 0 && a[2][3] % x2 == 0) check(i);
            x1 = a[1][2] / i, x2 = i;
            if (a[1][3] * x2 == a[2][3] * x1 && a[1][3] % x1 == 0 && a[2][3] % x2 == 0) check(a[1][2] / i);
        }
    }
    return 0;
}