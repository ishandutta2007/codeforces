#include <cstdio>

const int MAXN = 1000007;
const int MAXL = 20;

int deep[MAXN];
int prev[MAXN][MAXL];
int lg[MAXN];

int lca(int x, int y)
{
    for (int i = 0; i < 2; ++i) {
        while (deep[x] > deep[y]) {
            x = prev[x][lg[deep[x] - deep[y]]];
        }
        {
            int z = x;
            x = y;
            y = z;
        }
    }
    if (x == y) {
        return x;
    }

    for (int i = MAXL - 1; i >= 0; --i)
        if (prev[x][i] != prev[y][i]) {
            //printf("\t%d %d -> %d %d\n", x, y, prev[x][i], prev[y][i]);
            x = prev[x][i];
            y = prev[y][i];
        }
    return prev[x][0];
}

void chk(int a, int b, int &fs, int &sc, int &ans)
{
    int l = deep[a] + deep[b] - 2 * deep[lca(a, b)];
    //printf("%d %d -> %d = %d\n", a, b, lca(a, b), l);
    if (l > ans) {
        ans = l;
        fs = a;
        sc = b;
    }
}
        
int main()
{
    for (int i = 2; i < MAXN; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }

    for (int i = 2; i < 5; ++i) {
        prev[i][0] = 1;
        deep[i] = 1;
    }

    int fs, sc, ans;
    fs = 2;
    sc = 3;
    ans = 2;

    int m;
    int n = 4;
    scanf("%d", &m);

    while (m--) {
        int x;
        scanf("%d", &x);
        n += 2;
        prev[n - 1][0] = prev[n][0] = x;
        for (int i = 1; i < MAXL; ++i) {
            prev[n - 1][i] = prev[n][i] = prev[prev[n][i - 1]][i - 1];
        }
        deep[n - 1] = deep[n] = deep[x] + 1;

        chk(fs, n, fs, sc, ans);
        chk(sc, n, fs, sc, ans);
        printf("%d\n", ans);
    }
    
    return 0;
}