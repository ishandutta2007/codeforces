#include <bits/stdc++.h>
using namespace std;
const int N = 5004;
const int INF = 1000000007;
struct ban
{
    int c, d;
};

int n;
int b;
ban a[N];

vector<int> g[N];
int q[N];

int ans[N][N][2];

int tans[N][2];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i].c, &a[i].d);
        if (i >= 2)
        {
            int p;
            scanf("%d", &p);
            g[p].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
            ans[i][j][0] = ans[i][j][1] = INF;
    }

    for (int x = n; x >= 1; --x)
    {
        q[x] = 1;

        ans[x][0][0] = 0;
        ans[x][1][0] = a[x].c;

        ans[x][1][1] = a[x].c - a[x].d;

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];

            for (int j = 0; j <= n; ++j)
                tans[j][0] = tans[j][1] = INF;
            for (int j = 0; j <= q[x]; ++j)
            {
                for (int k = 0; k <= q[h]; ++k)
                {
                    if (j + k > n)
                        break;
                    tans[j + k][0] = min(tans[j + k][0], ans[x][j][0] + ans[h][k][0]);

                    tans[j + k][1] = min(tans[j + k][1], ans[x][j][1] + ans[h][k][0]);
                    tans[j + k][1] = min(tans[j + k][1], ans[x][j][1] + ans[h][k][1]);
                }
            }

            q[x] += q[h];

            for (int j = 0; j <= q[x]; ++j)
            {
                ans[x][j][0] = tans[j][0];
                ans[x][j][1] = tans[j][1];
            }
        }
    }

    int yans;
    for (int j = 0; j <= n; ++j)
    {
        if (ans[1][j][1] <= b || ans[1][j][0] <= b)
            yans = j;
    }
    cout << yans << endl;
    return 0;
}