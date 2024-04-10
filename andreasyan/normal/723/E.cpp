#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 202;

int n, m;
set<int> a[N];

vector<pair<int, int> > ans;

bool c[N * N];
void dfs(int x)
{
    if (!a[x].empty())
    {
        int y = *a[x].begin();
        ans.push_back(m_p(x, y));
        a[x].erase(y);
        a[y].erase(x);
        dfs(y);
    }
}

void solv()
{
    memset(c, false, sizeof c);
    ans.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        a[i].clear();
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].insert(y);
        a[y].insert(x);
    }
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size() % 2 == 0)
            ++q;
    }
    printf("%d\n", q);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size() % 2 == 1)
            dfs(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        dfs(i);
    }
    for (int i = 0; i < m; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}