#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 505;

int n, m, a[MN][MN], b[MN][MN];

int fth(int x) {
    for (int i = 1; i <= 100; i++) if (x == i * i * i * i) return i;
    return 0;
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] = 720720;
            if ((i + j) % 2) b[i][j] -= a[i][j] * a[i][j] * a[i][j] * a[i][j];
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}