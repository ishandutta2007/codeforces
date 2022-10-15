#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2503;
const int INF = (int)1e+9 + 7;

vector <int> e[MAXN];
vector <int> a[MAXN];
vector < vector <int> > v[MAXN];
int prev[MAXN];
int size[MAXN];
int f[MAXN][MAXN][3];
int g[3][MAXN][3];
int n, m;

void dfs_create(int x, int p = -1)
{
    if (prev[x]) {
        vector <int> a;
        for (int i = p; i != x; i = prev[i]) {
            a.push_back(i);
        }
        reverse(a.begin(), a.end());
        v[x].push_back(a);
        for (size_t i = 0; i < a.size(); ++i) {
            prev[a[i]] = 0;
        }
        prev[x] = 0;
        return;
    }

    for (size_t i = 0; i < e[x].size(); ++i) {
        int y = e[x][i];
        if (y != p && prev[y] != -2) {
            prev[x] = p;
            dfs_create(y, x);
            if (prev[x] == p) {
                v[x].push_back(vector <int> (1, y));
            }
        }
    }
    prev[x] = -2;
}

inline void maxi(int &x, const int v)
{
    if (x < v) {
        x = v;
    }
}

void dfs_calc(int x)
{
    size[x] = 1;
    for (size_t i = 0; i < v[x].size(); ++i)
        for (size_t j = 0; j < v[x][i].size(); ++j) {
            dfs_calc(v[x][i][j]);
            size[x] += size[v[x][i][j]];
        }

    for (int i = 0; i <= size[x]; ++i)
        for (int t = 0; t < 3; ++t)
            f[x][i][t] = -INF;

    f[x][0][0] = 0;
    f[x][1][1] = 0;
    f[x][0][2] = 1;

    for (int i = 0; i <= size[x]; ++i)
        for (int fs = 0; fs < 3; ++fs)
            for (int sc = 0; sc < 3; ++sc)
                g[fs][i][sc] = -INF;

    for (int i = 0; i <= size[x]; ++i)
        for (int t = 0; t < 3; ++t)
            g[t][i][t] = f[x][i][t];
/*
    printf("%d:\n", x);
    for (size_t i = 0; i < v[x].size(); ++i) {
        printf("\t%d.", i + 1);
        for (size_t j = 0; j < v[x][i].size(); ++j)
            printf(" %d", v[x][i][j]);
        printf("\n");
    }
//*/

    int s = 1;
    for (size_t i = 0; i < v[x].size(); ++i) {
        for (size_t j = 0; j < v[x][i].size(); ++j) {
            int y = v[x][i][j];
            s += size[y];
            for (int fs = 0; fs < 3; ++fs) {
                int G[3];
                for (int k = s; k >= 0; --k) {
                    for (int t = 0; t < 3; ++t)
                        G[t] = -INF;
                    for (int m = max(k - (s - size[y]), 0); m <= k && m <= size[y]; ++m)
                        for (int ls = 0; ls < 3; ++ls)
                            for (int t = 0; t < 3; ++t)
                                if (ls + t != 3)
                                    maxi(G[t], g[fs][k - m][ls] + f[y][m][t]);
                    for (int t = 0; t < 3; ++t)
                        g[fs][k][t] = G[t];
                }
            }
        }
        for (int fs = 0; fs < 3; ++fs)
            for (int k = s; k >= 0; --k)
                for (int ls = 0; ls < 3; ++ls) {
                    if (fs + ls != 3) {
                        maxi(g[fs][k][fs], g[fs][k][ls]);
                    }

                    if (fs != ls) {
                        g[fs][k][ls] = -INF;
                    }
                }
    }

    for (int fs = 0; fs < 3; ++fs)
        for (int k = s; k >= 0; --k)
            for (int ls = 0; ls < 3; ++ls)
                maxi(f[x][k][fs], g[fs][k][ls]);
    size[x] = s;
/*
    for (int fs = 0; fs < 3; ++fs)
        for (int k = size[x]; k >= 0; --k)
            if (f[x][k][fs] >= 0)
                printf("f[%d][%d][%d] = %d\n", x, k, fs, f[x][k][fs]);
//*/
}

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs_create(1);
    dfs_calc(1);

    for (int i = 0; i <= n; ++i) {
        int ans = -INF;
        for (int j = 0; j < 3; ++j)
            maxi(ans, f[1][i][j]);
        if (i) {
            printf(" ");
        }
        printf("%d", ans);
    }
    printf("\n");

    return 0;
}