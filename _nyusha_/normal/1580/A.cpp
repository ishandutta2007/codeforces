#include<bits/stdc++.h>

using namespace std;

int const maxn = 405;
int a[maxn][maxn];
int pref[maxn][maxn];
int c[maxn], f[maxn];
int inf = 1e9 + 7;

inline int get(int i1, int j1, int i2, int j2) {
    return pref[i2][j2] - pref[i1 - 1][j2] - pref[i2][j1 - 1] + pref[i1 - 1][j1 - 1];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            for (int j = 1; j <= m; ++j) {
                a[i][j] = s[j - 1] - '0';
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
            }
        }
        int ans = 21;
        for (int i1 = 1; i1 <= n; ++i1) {
            for (int i2 = i1 + 4; i2 <= n; ++i2) {
                for (int j = 1; j <= m; ++j) {
                    c[j] = (i2 - i1 - 1) - get(i1 + 1, j, i2 - 1, j);
                    f[j] = get(i1 + 1, j, i2 - 1, j);
                    f[j] += f[j - 1];
                    if (a[i1][j] == 0) f[j]++;
                    if (a[i2][j] == 0) f[j]++;
                }
                int imin = inf;
                for (int pos = 1; pos <= m; ++pos) {
                    if (pos >= 4) {
                        imin = min(imin, c[pos - 3] - f[pos - 3]);
                    }
                    ans = min(ans, imin + c[pos] + f[pos - 1]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}