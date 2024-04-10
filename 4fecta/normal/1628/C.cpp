#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1005;

int t, n, adj[MN][MN], tmp[MN][MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> adj[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i += 2) {
            for (int j = 1; j <= n; j += 2) {
                if ((i + j) % 4 == 2) ans ^= adj[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i + j) % 4 == 2 && (i + j) > n + 1) {
                    ans ^= adj[i][j];
                    //printf("%lld %lld\n", i, j);
                }
            }
        }
        //printf("%lld ", ans);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                tmp[n - j + 1][i] = adj[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = tmp[i][j];
            }
        }
        for (int i = 1; i <= n; i += 2) {
            for (int j = 1; j <= n; j += 2) {
                if ((i + j) % 4 == 2) ans ^= adj[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i + j) % 4 == 2 && (i + j) > n + 1) {
                    ans ^= adj[i][j];
                    //printf("%lld %lld\n", i, j);
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}