#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;

int g[MAXN][MAXN][MAXN];

int v, vv, vvv;

bool can(int a, int b, int c, int d, int e, int f) {
    if (a > d || b > e || c > f) return 0;
    if (g[d][e][f] == 0) return 1;
    if (g[a][b][c] == 0) return 0;
    if (a == d && b == e && c == f) return 1;
    bool state = false;
    if (a + 1 != v || b != vv || c != vvv) 
        state |= can(a + 1, b, c, d, e, f);
    if (a != v || b + 1 != vv || c != vvv)
        state |= can(a, b + 1, c, d, e, f);
    if (a != v || b != vv || c + 1 != vvv)
        state |= can(a, b, c + 1, d, e, f);
    return state;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            string s;
            cin >> s;
            for (int z = 1; z <= k; z++) {
                g[i][j][z] = (s[z - 1] == '1');
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int z = 1; z <= k; z++) {
                if (!g[i][j][z]) continue;
                bool logic = false;
                v = i, vv = j, vvv = z;
                if (g[i - 1][j][z]) 
                    if (!can(i - 1, j, z, i + 1, j, z) || !can(i - 1, j, z, i, j + 1, z) || !can(i - 1, j, z, i, j, z + 1))
                        logic = 1;
                if (!logic && g[i][j - 1][z]) 
                    if (!can(i, j - 1, z, i + 1, j, z) || !can(i, j - 1, z, i, j + 1, z) || !can(i, j - 1, z, i, j, z + 1))
                        logic = 1;
                if (!logic && g[i][j][z - 1]) 
                    if (!can(i, j, z - 1, i + 1, j, z) || !can(i, j, z - 1, i, j + 1, z) || !can(i, j, z - 1, i, j, z + 1))
                        logic = 1;
                res += logic;
            }
        }
    }
    cout << res << endl;
}