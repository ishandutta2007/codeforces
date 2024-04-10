#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, m, q;
int a[N], u[N];
int b[N];
int t[N];

vector<int> g[N];

int maxu[N];
vector<int> pp;
bool c[N];
void dfs(int x)
{
    c[x] = true;
    pp.push_back(x);
    if (pp.size() >= n)
    {
        maxu[x] = pp[pp.size() - n];
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
    }
    pp.pop_back();
}

vector<pair<int, int> > v[N];
char ans[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        u[a[i]] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &b[i]);
        b[i] = u[b[i]];
    }
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        v[r].push_back(m_p(l, i));
    }
    for (int i = 1; i <= m; ++i)
    {
        if (b[i] == 1)
        {
            if (t[n])
                g[t[n]].push_back(i);
        }
        else
        {
            if (t[b[i] - 1])
                g[t[b[i] - 1]].push_back(i);
        }
        t[b[i]] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        if (!c[i])
            dfs(i);
    }
    int yans = 0;
    for (int i = 1; i <= m; ++i)
    {
        yans = max(yans, maxu[i]);
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j].first <= yans)
                ans[v[i][j].second] = '1';
            else
                ans[v[i][j].second] = '0';
        }
    }
    printf("%s\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}