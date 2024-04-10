#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
const long long INF = 1000000009000000009;

int n, m, aa, bb, cc;
int b[N];
long long p[N];
vector<int> a[N];

bool c[N];
void bfs(int x, int d[])
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    queue<int> q;
    d[x] = 0;
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

int da[N], db[N], dc[N];

void solv()
{
    scanf("%d%d%d%d%d", &n, &m, &aa, &bb, &cc);
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; ++i)
        p[i] = p[i - 1] + b[i];
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bfs(aa, da);
    bfs(bb, db);
    bfs(cc, dc);
    long long ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        if (db[i] + da[i] + dc[i] > m)
            continue;
        long long yans = p[db[i]] * 2;
        yans += (p[db[i] + da[i] + dc[i]] - p[db[i]]);
        ans = min(ans, yans);
    }
    printf("%I64d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}