#include <bits/stdc++.h>

using namespace std;

int const maxn = 705;
int lef[maxn][maxn];
int righ[maxn][maxn];
int a[maxn];
int ok[maxn][maxn];

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int c = a % b;
        a = b, b = c;
    }
    return a + b;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) if (gcd(a[i], a[j]) > 1) ok[i][j] = 1;
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (len == 1) lef[i][j] = 1, righ[i][j] = 1;
            else {
                for (int mid = i + 1; mid <= j; ++mid) {
                    if (ok[i][mid]) {
                        lef[i][j] = (lef[i][j]|(righ[i + 1][mid]&lef[mid][j]));
                    }
                }
                for (int mid = i; mid < j; ++mid) {
                    if (ok[mid][j]) {
                        righ[i][j] = (righ[i][j]|(righ[i][mid]&lef[mid][j - 1]));
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans|(righ[1][i]&lef[i][n]));
    if (ans) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}