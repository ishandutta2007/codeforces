#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int n, m;
    cin >> n >> m;
    char a[n + 5][m + 5];
    memset(a, '$', sizeof(a));
    int psa[n + 5][m + 5];
    memset(psa, 0, sizeof(psa));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X') psa[i][j] = 1;
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int sum = psa[n][r] - psa[n][l];
        if (sum) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}