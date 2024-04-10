#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
vector<int> a[N];

const int m = 20;
int p[N][m];
int d[N];
int tin[N], tout[N], ti;

void dfs(int x)
{
    tin[x] = ++ti;
    for (int i = 1; i < m; ++i)
        p[x][i] = p[p[x][i - 1]][i - 1];
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        d[h] = d[x] + 1;
        dfs(h);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y)
{
    if (isp(x, y))
        return x;
    if (isp(y, x))
        return y;
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
            x = p[x][i];
    }
    return p[x][0];
}

void solv()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
    {
        scanf(" %d", &p[i][0]);
        a[p[i][0]].push_back(i);
    }
    p[1][0] = 1;
    dfs(1);
    int x = 1;
    int y = 1;
    int ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        int z = lca(x, i);
        int yans = d[x] + d[i] - 2 * d[z];
        int z1 = lca(y, i);
        int yans1 = d[y] + d[i] - 2 * d[z1];
        if (yans >= yans1 && yans >= ans)
        {
            ans = yans;
            y = i;
        }
        else if (yans1 >= yans && yans1 >= ans)
        {
            ans = yans1;
            x = i;
        }
        printf("%d ", ans);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}