#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003, M = 998244353;

int n;
char a[N];

vector<pair<int, int> > g[N];
void ave(int x, int y, int z)
{
    g[x].push_back(m_p(y, z));
    g[y].push_back(m_p(x, z));
}

int c[N];
int k;

void dfs0(int x)
{
    c[x] = k;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (g[x][i].se == 0)
        {
            if (!c[h])
                dfs0(h);
        }
    }
}

vector<int> gg[N];

int kk;
bool dfs1(int x, int g)
{
    c[x] = g;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (!c[h])
        {
            if (!dfs1(h, 3 - g))
                return false;
        }
        else
        {
            if (c[h] == c[x])
                return false;
        }
    }
    return true;
}

int solvv()
{
    memset(c, 0, sizeof c);
    k = 0;
    for (int x = 1; x <= n * 2 + 2; ++x)
    {
        if (!c[x])
        {
            ++k;
            dfs0(x);
        }
    }

    for (int i = 1; i <= k; ++i)
        gg[i].clear();
    for (int x = 1; x <= n * 2 + 2; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int y = g[x][i].fi;
            if (g[x][i].se == 1)
                gg[c[x]].push_back(c[y]);
        }
    }

    memset(c, 0, sizeof c);
    kk = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (!c[i])
        {
            ++kk;
            if (!dfs1(i, 1))
                return 0;
        }
    }

    int ans = 1;
    for (int i = 1; i < kk; ++i)
        ans = (ans * 2) % M;
    return ans;
}

void solv()
{
    scanf(" %s", a);
    n = strlen(a);

    int ans = 0;
    for (int m = n - 1; m >= 1; --m)
    {
        for (int x = 1; x <= n * 2 + 2; ++x)
            g[x].clear();
        for (int x = 1; x <= n; ++x)
        {
            if (a[x - 1] == '0')
                ave(x, x + n, 0);
            else if (a[x - 1] == '1')
                ave(x, x + n, 1);
        }
        for (int x = 1, y = n; x < y; ++x, --y)
        {
            ave(x, y, 0);
        }
        int s = n + (n - m) + 1;
        for (int x = s, y = n + n; x < y; ++x, --y)
        {
            ave(x, y, 0);
        }

        int x0 = n + n + 1;
        int x1 = n + n + 2;
        ave(x0, x1, 1);

        ave(x1, 1, 0);
        ave(x1, s, 0);
        for (int x = n + 1; x < s; ++x)
            ave(x0, x, 0);

        ans = (ans + solvv()) % M;
    }
    printf("%d\n", ans);
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