#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 405;

int a[MN][MN], psa[MN][MN];
char c;

inline int sum(int l, int r, int t, int b) {
    return psa[b][r] - psa[b][l - 1] - psa[t - 1][r] + psa[t - 1][l - 1];
}

inline int cost(int l, int r, int t, int b) {
    int ret = sum(l + 1, r - 1, t + 1, b - 1);
    ret += r - l - 1 - sum(l + 1, r - 1, t, t);
    ret += r - l - 1 - sum(l + 1, r - 1, b, b);
    ret += b - t - 1 - sum(l, l, t + 1, b - 1);
    ret += b - t - 1 - sum(r, r, t + 1, b - 1);
    return ret;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c;
                a[i][j] = c - '0';
                psa[i][j] = a[i][j] + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
            }
        }
        int ans = 0x3f3f3f3f;
        for (int l = 1; l <= m; l++) {
            for (int r = l + 3; r <= m; r++) {
                int best = 1;
                for (int i = 5; i <= n; i++) {
                    int j = i - 4;
                    if (cost(l, r, j, i) < cost(l, r, best, i)) best = j;
                    ans = min(ans, cost(l, r, best, i));
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}