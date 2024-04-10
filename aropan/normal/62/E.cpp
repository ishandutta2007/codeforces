#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 5;
const int MAXK = 1 << MAXN;
const int MAXM = 111111;
const long long INF = (long long)(1e+18);

int ver[MAXN][MAXM];
int hor[MAXN][MAXM];
long long f[MAXN + 1][MAXK];
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &hor[j][i]);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &ver[j][i]);

    int k = 1 << n;
    for (int j = 0; j <= MAXN; j++)
        for (int z = 0; z < MAXK; z++)
            f[j][z] = INF;

    f[0][0] = 0;
    for (int i = 1; i < m; i++)
    {
        for (int l = 0; l < n; l++)
            for (int x = 0; x < k; x++)
                if (f[l][x] < INF)
                {

                    for (int b = 0; b < 2; b++)
                    {
                        long long res = f[l][x];
                        if (((x >> l) & 1) != b) res += hor[l][i - 1];
                        if (l && ((x >> (l - 1)) & 1) != b) res += ver[l - 1][i];
                        int j = (x ^ (((x >> l) & 1) << l)) | (b << l);
                        f[l + 1][j] = min(f[l + 1][j], res);
                    }
                    f[l][x] = INF;
                }

        for (int x = 0; x < k; x++)
        {
            f[0][x] = f[n][x] + ver[n - 1][i] * (((x >> (n - 1)) & 1) != (x & 1));
            f[n][x] = INF;
        }
    }
    cout << f[0][(1 << n) - 1] << endl;
    return 0;
}