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
const pair<int, int> M = m_p(781908917, 956603663);
const int P = 300007;

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}

pair<int, int> ast[N];
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int n, m;
vector<int> a[N];

pair<int, int> hh[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

set<int> g[N];

int c[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        a[i].push_back(i);
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            hh[x] = sum(hh[x], ast[h]);
        }
    }
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (hh[x] == hh[y])
            {
                kpc(x, y);
            }
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (fi(x) != fi(y))
            {
                g[fi(x)].insert(fi(y));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (g[i].size() > 2)
        {
            printf("NO\n");
            return;
        }
    }
    int x = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (g[i].size() == 1)
        {
            x = i;
            break;
        }
    }
    if (x == -1)
    {
        x = fi(1);
        for (int i = 1; i <= n; ++i)
        {
            if (g[i].size() == 2)
            {
                x = -1;
                break;
            }
        }
    }
    if (x == -1)
    {
        printf("NO\n");
        return;
    }
    c[x] = 1;
    while (1)
    {
        bool z = false;
        for (set<int>::iterator it = g[x].begin(); it != g[x].end(); ++it)
        {
            int h = *it;
            if (!c[h])
            {
                c[h] = c[x] + 1;
                x = h;
                z = true;
                break;
            }
        }
        if (!z)
            break;
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", c[fi(i)]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}