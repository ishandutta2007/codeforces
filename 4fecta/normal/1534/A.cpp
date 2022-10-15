#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int t, n, m, a[55][55], b[55][55];
char c;

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c;
                if (c == 'R') a[i][j] = 2;
                if (c == 'W') a[i][j] = 1;
            }
        }
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((i + j) % 2) {
                    b[i][j] = 2;
                    if (a[i][j] == 1) ok = 0;
                } else {
                    b[i][j] = 1;
                    if (a[i][j] == 2) ok = 0;
                }
            }
        }
        if (!ok) {
            ok = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if ((i + j) % 2) {
                        b[i][j] = 1;
                        if (a[i][j] == 2) ok = 0;
                    } else {
                        b[i][j] = 2;
                        if (a[i][j] == 1) ok = 0;
                    }
                }
            }
        }
        if (!ok) printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (b[i][j] == 1) printf("W");
                    else printf("R");
                }
                printf("\n");
            }
        }
    }

    return 0;
}