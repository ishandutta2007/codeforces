#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 252, INF = 1000006;

int n, m;
int aa[N], bb[N];
int sa, sb;
pair<int, int> b[N];
int a[N][N];

bool c[N];
int p[N];

bool bfs()
{
    memset(c, false, sizeof c);
    queue<int> q;
    c[0] = true;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == n + n + 1)
            return true;
        for (int h = 0; h <= n + n + 1; ++h)
        {
            if (a[x][h])
            {
                if (!c[h])
                {
                    c[h] = true;
                    p[h] = x;
                    q.push(h);
                }
            }
        }
    }
    return false;
}

int ans[N][N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &aa[i]);
        sa += aa[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &bb[i]);
        sb += bb[i];
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &b[i].first, &b[i].second);
    }
    if (sa != sb)
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        a[0][i] = aa[i];
    for (int i = 1; i <= n; ++i)
        a[i + n][n + n + 1] = bb[i];
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].first;
        int y = b[i].second;
        a[x][n + y] = INF;
        a[y][n + x] = INF;
    }
    for (int i = 1; i <= n; ++i)
        a[i][n + i] = INF;
    while (1)
    {
        if (!bfs())
            break;
        int minu = INF;
        for (int x = n + n + 1; x != 0; x = p[x])
        {
            minu = min(minu, a[p[x]][x]);
        }
        for (int x = n + n + 1; x != 0; x = p[x])
        {
            a[p[x]][x] -= minu;
            a[x][p[x]] += minu;
        }
    }
    int s = 0;
    for (int x = 0; x <= n + n + 1; ++x)
    {
        s += a[x][0];
    }
    if (s != sa)
    {
        printf("NO\n");
        return 0;
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int y = n + 1; y <= n + n; ++y)
        {
            ans[x][y - n] = a[y][x];
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}