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

int n, m, a[MN], b[MN];
char c;

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int sum = 0;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            cin >> c;
            a[i] = c - '0';
        }
        for (int i = 1; i <= m; i++) {
            memset(b, 0, sizeof(b));
            for (int j = 1; j <= n; j++) {
                if (a[j] || a[j - 1] + a[j + 1] == 1) b[j] = 1;
            }
            int ch = 0;
            for (int j = 1; j <= n; j++) {
                if (b[j] != a[j]) ch = 1;
                a[j] = b[j];
            }
            if (!ch) break;
        }
        for (int i = 1; i <= n; i++) printf("%d", a[i]);
        printf("\n");
    }

    return 0;
}