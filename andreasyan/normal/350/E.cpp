#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 404;

int n, k, m;
int a[N];

bool u[N][N];

set<pair<int, int> > s;

bool c[N];
void dfs(int x)
{
    c[x] = true;
    for (int h = 1; h <= n; ++h)
    {
        if (!u[x][h])
            continue;
        if (!c[h])
        {
            s.insert(m_p(min(x, h), max(x, h)));
            dfs(h);
        }
    }
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + k + 1);
    if (k == n)
    {
        printf("-1\n");
        return;
    }
    if (m > n * (n - 1) / 2 - k + 1)
    {
        printf("-1\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            if (i == a[1])
            {
                if (!binary_search(a + 1, a + k + 1, j))
                    u[i][j] = true;
            }
            else if (j == a[1])
            {
                if (!binary_search(a + 1, a + k + 1, i))
                    u[i][j] = true;
            }
            else
                u[i][j] = true;
        }
    }
    dfs(1);
    m -= (n - 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (!u[i][j])
                continue;
            if (s.find(m_p(i, j)) != s.end())
                continue;
            if (m)
            {
                --m;
                s.insert(m_p(i, j));
            }
        }
    }
    for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it)
        printf("%d %d\n", it->first, it->second);
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