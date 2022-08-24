#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 1;
vector <int> g[N];
set <int> s[N];
int c[N];
int tin[N];
int tout[N];
int sz = 0;
bool bad[N];
bool bbad[N];
bool good[N];
int col[N];
int who[N][2];

void dfs(int v, int pr)
{
    col[sz] = c[v];
    tin[v] = sz++;
    good[v] = 1;
    for (auto to : g[v])
    {
        if (to != pr)
        {
            dfs(to, v);
            if (!good[to])
            {
                good[v] = 0;
            }
            if (s[to].size() != 1)
            {
                good[v] = 0;
            }
            else
            {
                s[v].insert(*s[to].begin());
            }
        }
    }
    s[v].insert(c[v]);
    col[sz] = c[v];
    tout[v] = sz++;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    dfs(1, -1);
    bad[0] = 0;
    who[0][0] = col[0];
    for (int i = 1; i < sz; i++)
    {
        if (bad[i - 1])
        {
            bad[i] = 1;
        }
        else
        {
            if (col[i] != col[i - 1])
            {
                bad[i] = 1;
            }
        }
        who[i][0] = who[i - 1][0];
    }
    bbad[sz - 1] = 0;
    who[sz - 1][1] = col[sz - 1];
    for (int i = sz - 2; i >= 0; i--)
    {
        if (bbad[i + 1])
        {
            bbad[i] = 1;
        }
        else
        {
            if (col[i] != col[i + 1])
            {
                bbad[i] = 1;
            }
        }
        who[i][1] = who[i + 1][1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (good[i])
        {
            if (tin[i] != 0 && tout[i] != sz - 1)
            {
                if (!bad[tin[i] - 1] && !bbad[tout[i] + 1] && who[tin[i] - 1][0] == who[tout[i] + 1][1])
                {
                    puts("YES");
                    printf("%d\n", i);
                    return 0;
                }
            }
            else if (tin[i] != 0)
            {
                if (!bad[tin[i] - 1])
                {
                    puts("YES");
                    printf("%d\n", i);
                    return 0;
                }
            }
            else
            {
                if (!bbad[tout[i] + 1])
                {
                    puts("YES");
                    printf("%d\n", i);
                    return 0;
                }
            }
        }
    }
    puts("NO");
}