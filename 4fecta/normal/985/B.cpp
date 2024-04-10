#include <bits/stdc++.h>
using namespace std;
const int MN = 2005;
int n, m, a[MN][MN], cnt[MN];
int main() {
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c; a[i][j] = c - '0';
            cnt[j] += a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cnt[j] -= a[i][j];
        int tmp = 0;
        for (int j = 1; j <= m; j++) if (cnt[j]) tmp++;
        if (tmp == m) return 0 * printf("YES\n");
        for (int j = 1; j <= m; j++) cnt[j] += a[i][j];
    }
    printf("NO\n");
}