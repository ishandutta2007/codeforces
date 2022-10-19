#include <bits/stdc++.h>
using namespace std;
const int N = 300005, INF = 1000000009;

int n, k;
char a[N];

vector<int> b[N];

int p[N];
vector<int> v[N];
int u[N][2];
int ans[N][2];
int yans;

int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= k; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            b[x].push_back(i);
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        p[i] = i;
        v[i].push_back(i);
        u[i][0] = 0;
        ans[i][0] = 0;
        u[i][1] = 1;
        ans[i][1] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (b[i].empty())
        {
            printf("%d\n", yans);
            continue;
        }
        if (b[i].size() == 1)
        {
            int x = b[i][0];
            yans -= min(ans[fi(x)][0], ans[fi(x)][1]);
            if (a[i] == '0')
            {
                if (u[x][1] == 0)
                {
                    ans[fi(x)][1] = INF;
                }
                else
                {
                    ans[fi(x)][0] = INF;
                }
            }
            else
            {
                if (u[x][0] == 0)
                {
                    ans[fi(x)][1] = INF;
                }
                else
                {
                    ans[fi(x)][0] = INF;
                }
            }
            yans += min(ans[fi(x)][0], ans[fi(x)][1]);
        }
        else
        {
            int x = b[i][0];
            int y = b[i][1];
            if (fi(x) == fi(y))
            {
                printf("%d\n", yans);
                continue;
            }
            int xx = fi(x);
            int yy = fi(y);
            if (v[xx].size() > v[yy].size())
            {
                swap(x, y);
                swap(xx, yy);
            }
            p[xx] = yy;
            for (int i = 0; i < v[xx].size(); ++i)
            {
                v[yy].push_back(v[xx][i]);
            }
            yans -= min(ans[xx][0], ans[xx][1]);
            yans -= min(ans[yy][0], ans[yy][1]);
            for (int k = 0; k < 2; ++k)
            {
                for (int j = 0; j < 2; ++j)
                {
                    if ((u[x][k] ^ u[y][j]) == ((a[i] - '0') ^ 1))
                    {
                        if (k != j)
                        {
                            for (int i = 0; i < v[xx].size(); ++i)
                            {
                                swap(u[v[xx][i]][0], u[v[xx][i]][1]);
                            }
                            swap(ans[xx][0], ans[xx][1]);
                            break;
                        }
                    }
                }
            }
            for (int k = 0; k < 2; ++k)
            {
                ans[yy][k] = min(INF, (ans[xx][k] + ans[yy][k]));
            }
            yans += min(ans[yy][0], ans[yy][1]);
        }
        printf("%d\n", yans);
    }
    return 0;
}