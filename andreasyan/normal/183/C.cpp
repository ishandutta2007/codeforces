#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m;
vector<pair<int, int> > a[N];

int c[N];
int d = -1;
void dfs(int x)
{
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (!c[h])
        {
            c[h] = c[x] + a[x][i].second;
            dfs(h);
        }
        else
        {
            if (c[h] != c[x] + a[x][i].second)
            {
                d = abs(c[h] - (c[x] + a[x][i].second));
            }
        }
    }
}

bool cc[N];
void dfs1(int x, int d)
{
    cc[x] = true;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (!cc[h])
        {
            c[h] = (c[x] + a[x][i].second + d) % d;
            dfs1(h, d);
        }
    }
}

bool stg(int d)
{
    memset(cc, false, sizeof cc);
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        if (!cc[i])
            dfs1(i, d);
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i].first;
            if (c[y] != (c[x] + a[x][i].second + d) % d)
                return false;
        }
    }
    return true;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(m_p(y, 1));
        a[y].push_back(m_p(x, -1));
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            c[i] = N;
            dfs(i);
        }
    }
    if (d == -1)
    {
        printf("%d\n", n);
        return;
    }
    for (int i = d; i >= 1; --i)
    {
        if (d % i == 0)
        {
            if (stg(i))
            {
                printf("%d\n", i);
                return;
            }
        }
    }
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