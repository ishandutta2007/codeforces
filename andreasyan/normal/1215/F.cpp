#include <bits/stdc++.h>
using namespace std;
const int N = 400005, k = 800000;

int q, n, M, m;
int l[N], r[N];

vector<int> a[N * 4], b[N * 4];
void ave(int x, int y)
{
    a[-x + k].push_back(y + k);
    a[-y + k].push_back(x + k);
    b[y + k].push_back(-x + k);
    b[x + k].push_back(-y + k);
}

vector<int> v;
int c[N * 4];
void dfs0(int x)
{
    c[x] = 1;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (c[h] == 0)
            dfs0(h);
    }
    v.push_back(x);
}

int kk;
void dfs1(int x)
{
    c[x] = kk;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int h = b[x][i];
        if (!c[h])
            dfs1(h);
    }
}

int pos[N * 2];

bool ans[N * 2];
int main()
{
    scanf("%d%d%d%d", &q, &n, &M, &m);
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ave(x, y);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &l[i], &r[i]);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ave(-x, -y);
    }
    for (int i = n + 1; i <= n + M - 1; ++i)
    {
        ave(i, -(i + 1));
    }
    for (int i = 1; i <= n; ++i)
    {
        ave(-i, (n + l[i]));
        if (r[i] + 1 <= M)
            ave(-i, -(n + r[i] + 1));
    }
    for (int i = -(n + M) + k; i <= n + M + k; ++i)
    {
        if (i == 0)
            continue;
        if (c[i] == 0)
            dfs0(i);
    }
    reverse(v.begin(), v.end());
    memset(c, 0, sizeof c);
    for (int i = 0; i < v.size(); ++i)
    {
        int x = v[i];
        if (c[x] == 0)
        {
            ++kk;
            dfs1(x);
        }
    }
    for (int i = 1; i <= n + M; ++i)
    {
        if (c[i + k] == c[-i + k])
        {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        pos[v[i]] = i;
    }
    for (int i = 1; i <= n + M; ++i)
    {
        if (pos[i + k] < pos[-i + k])
            ans[i] = false;
        else
            ans[i] = true;
    }
    int f = 0;
    for (int i = n + M; i >= n + 1; --i)
    {
        if (ans[i])
        {
            f = i - n;
            break;
        }
    }
    vector<int> yans;
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i])
            yans.push_back(i);
    }
    printf("%d %d\n", yans.size(), f);
    for (int i = 0; i < yans.size(); ++i)
        printf("%d ", yans[i]);
    printf("\n");
    return 0;
}