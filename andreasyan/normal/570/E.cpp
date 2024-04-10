#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 503, M = 1000000007;
const int xx[4] = {1, 0, -1, 0};
const int yy[4] = {0, 1, 0, -1};

int n, m;
char a[N][N];

vector<pair<int, int> > v[N + N];
int u[N][N];

int dp[N][N];
int ndp[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            u[i][j] = v[i + j].size();
            v[i + j].push_back(m_p(i, j));
        }
    }
    if ((n + m - 1) % 2 == 1)
    {
        for (int i = 0; i < v[(n + m) / 2 - 1].size(); ++i)
        {
            dp[i][i] = 1;
        }
    }
    else
    {
        for (int i = 0; i < v[(n + m) / 2 - 1].size(); ++i)
        {
            int x = v[(n + m) / 2 - 1][i].first;
            int y = v[(n + m) / 2 - 1][i].second;
            for (int j = 0; j < 2; ++j)
            {
                int hx = x + xx[j];
                int hy = y + yy[j];
                if (hx < n && hy < m && a[x][y] == a[hx][hy])
                {
                    dp[i][u[hx][hy]] = 1;
                }
            }
        }
    }
    for (int s = (n + m) / 2 - 1; s > 0; --s)
    {
        int f = (n + m - 2) - s;
        memset(ndp, 0, sizeof ndp);
        for (int i = 0; i < v[s].size(); ++i)
        {
            int xs = v[s][i].first;
            int ys = v[s][i].second;
            for (int j = 0; j < v[f].size(); ++j)
            {
                if (dp[i][j] == 0)
                    continue;
                int xf = v[f][j].first;
                int yf = v[f][j].second;
                for (int ii = 2; ii < 4; ++ii)
                {
                    int hxs = xs + xx[ii];
                    int hys = ys + yy[ii];
                    if (!(hxs >= 0 && hys >= 0))
                        continue;
                    for (int jj = 0; jj < 2; ++jj)
                    {
                        int hxf = xf + xx[jj];
                        int hyf = yf + yy[jj];
                        if (!(hxf < n && hyf < m))
                            continue;
                        if (a[hxs][hys] == a[hxf][hyf])
                            ndp[u[hxs][hys]][u[hxf][hyf]] = (ndp[u[hxs][hys]][u[hxf][hyf]] + dp[i][j]) % M;
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }
    printf("%d\n", dp[0][0]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}