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
const int N = 300005;

int n, m;
vector<int> a[N], b[N], z[N];
int s, f;

bool kam[N];

int c[N];
int fup[N], tin[N], ti;
void dfs0(int x, int pk)
{
    c[x] = 1;
    fup[x] = tin[x] = ++ti;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (b[x][i] == pk)
            continue;
        if (c[h])
        {
            fup[x] = min(fup[x], tin[h]);
        }
        else
        {
            dfs0(h, b[x][i]);
            if (fup[h] > tin[x])
            {
                kam[b[x][i]] = true;
            }
            fup[x] = min(fup[x], fup[h]);
        }
    }
}

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (kam[b[x][i]])
            continue;
        if (!c[h])
            dfs1(h);
    }
}

bool art[N];
vector<int> g[N], gz[N];

bool ans;
bool dfs(int x, int p, bool artt)
{
    artt |= art[x];
    if (x == f)
    {
        ans = artt;
        return true;
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (dfs(h, x, artt | gz[x][i]))
            return true;
    }
    return false;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        a[x].push_back(y);
        a[y].push_back(x);
        b[x].push_back(i);
        b[y].push_back(i);
        z[x].push_back(d);
        z[y].push_back(d);
    }
    scanf("%d%d", &s, &f);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            dfs0(i, -1);
        }
    }
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ++k;
            dfs1(i);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (c[x] == c[y])
            {
                if (z[x][i])
                    art[c[x]] = true;
            }
            else
            {
                g[c[x]].push_back(c[y]);
                gz[c[x]].push_back(z[x][i]);
            }
        }
    }
    s = c[s];
    f = c[f];
    dfs(s, s, false);
    if (ans)
        printf("YES\n");
    else
        printf("NO\n");
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