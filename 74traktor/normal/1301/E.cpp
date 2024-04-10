#include<bits/stdc++.h>

using namespace std;

int const maxn = 505;
char a[505][505];
int pref[maxn][maxn][4];
map < char, int > f = {{'R', 0}, {'G', 1}, {'Y', 2}, {'B', 3}};
int go[maxn][maxn];
int n, m;
int best[maxn][maxn][maxn];

inline int sum(int lx, int ly, int rx, int ry, int t) {
    if (lx <= 0 || ly <= 0 || rx > n || ry > m) return -1;
    return pref[rx][ry][t] + pref[lx - 1][ly - 1][t] - pref[rx][ly - 1][t] - pref[lx - 1][ry][t];
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, r1, c1, r2, c2;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
        for (int j = 1; j <= m; ++j) {
            for (int z = 0; z <= 3; ++z) pref[i][j][z] = pref[i - 1][j][z] + pref[i][j - 1][z] - pref[i - 1][j - 1][z];
            pref[i][j][f[a[i][j]]]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'R') {
                for (int z = 1;; ++z) {
                    if (sum(i - z + 1, j - z + 1, i, j, 0) == z * z && sum(i - z + 1, j + 1, i, j + z, 1) == z * z && sum(i + 1, j - z + 1, i + z, j, 2) == z * z && sum(i + 1, j + 1, i + z, j + z, 3) == z * z) {
                        go[i][j] = z;
                    }
                    else break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int good = -1;
            for (int z = j; z <= m; ++z) {
                if (go[i][z] != 0) good = z;
                if (good != -1) best[i][j][z] = max(best[i][j][z], min({go[i][good], good - j + 1, z - good}));
            }
        }
        for (int len = 1; len <= m; ++len) {
            for (int lef = 1; lef + len - 1 <= m; ++lef) {
                best[i][lef][lef + len - 1] = max({best[i][lef][lef + len - 1], best[i][lef + 1][lef + len - 1], best[i][lef][lef + len - 2]});
            }
        }
    }
    for (int i = 1; i <= q; ++i) {
        int ans = 0;
        cin >> r1 >> c1 >> r2 >> c2;
        for (int j = r1; j <= r2; ++j) {
            ans = max(ans, min({j - r1 + 1, r2 - j, best[j][c1][c2]}));
        }
        cout << (ans + ans) * (ans + ans) << '\n';
    }
    return 0;
}