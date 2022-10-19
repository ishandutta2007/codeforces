#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n, m;
vector<int> a[N], ar[N];
vector<int> g[N];

int k;
int b[N];

bool c[N];

int d[N];

void bfs()
{
    int x = b[1];
    queue<int> q;
    c[x] = true;
    q.push(x);
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            if (!c[h])
            {
                d[h] = d[x] + 1;
                c[h] = true;
                q.push(h);
            }
        }
    }
}

int dr[N];

void bfsr()
{
    int x = b[k];
    queue<int> q;
    c[x] = true;
    q.push(x);
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < ar[x].size(); ++i)
        {
            int h = ar[x][i];
            if (!c[h])
            {
                dr[h] = dr[x] + 1;
                c[h] = true;
                q.push(h);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        ar[y].push_back(x);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &b[i]);
    bfs();
    memset(c, false, sizeof c);
    bfsr();
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (1 + dr[y] == dr[x])
                g[x].push_back(y);
        }
        sort(g[x].begin(), g[x].end());
    }
    int minu = 0;
    int maxu = 0;
    for (int i = 1; i < k; ++i)
    {
        int x = b[i];
        int y = b[i + 1];
        if (!binary_search(g[x].begin(), g[x].end(), y))
            ++minu;
        if (g[x].size() > 1 || (!g[x].empty() && y != g[x][0]))
            ++maxu;
    }
    printf("%d %d\n", minu, maxu);
    return 0;
}