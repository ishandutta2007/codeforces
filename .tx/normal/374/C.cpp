#include <bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int d[1111][1111];
int c[1111][1111];
char s[1111];
int a[1111][1111];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

void dfs(int vx, int vy) {
    c[vx][vy] = 1;
    int ct = a[vx][vy];
    int nt = (ct + 1) % 4;
    for (int i = 0; i < 4; i++) {
        int x = vx + dx[i];
        int y = vy + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] != nt) {
            continue;
        }
        if (c[x][y] == 1) {
            puts("Poor Inna!");
            exit(0);
        }
        if (c[x][y] == 0) {
            dfs(x, y);
        }
        d[vx][vy] = max(d[vx][vy], d[x][y]);
    }
    if (ct == 3) {
        d[vx][vy]++;
    }
    c[vx][vy] = 2;
}

int main() {
    scii(n, m);
    char tn[256];
    tn['D'] = 0;
    tn['I'] = 1;
    tn['M'] = 2;
    tn['A'] = 3;
    for (int i = 0; i < n; i++) {
        scanf("\n%s", s);
        for (int j = 0; j < m; j++) {
            a[i][j] = tn[s[j]];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && c[i][j] == 0) {
                dfs(i, j);
            }
            ans = max(ans, d[i][j]);
        }
    }

    if (ans == 0) {
        puts("Poor Dima!");
    } else {
        cout << ans;
    }

    return 0;
}