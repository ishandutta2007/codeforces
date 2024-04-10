#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;
struct ban
{
    int x, y, d;
};
bool operator<(const ban& a, const ban& b)
{
    return a.d < b.d;
}

int n;
ban b[N];
bool c[N];

int p[N];
int fi(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

vector<pair<int, int> > a[N];

const int m = 19;
int pp[N][m];
int maxu[N][m];
int tin[N], tout[N], ti;

void dfs(int x, int p0, int kp)
{
    tin[x] = ++ti;
    pp[x][0] = p0;
    maxu[x][0] = kp;
    for (int i = 1; i < m; ++i)
    {
        pp[x][i] = pp[pp[x][i - 1]][i - 1];
        maxu[x][i] = max(maxu[x][i - 1], maxu[pp[x][i - 1]][i - 1]);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i].first;
        if (h == p0)
            continue;
        dfs(h, x, a[x][i].second);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int go(int x, int y)
{
    if (isp(x, y))
        return 0;
    int ans = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(pp[x][i], y))
        {
            ans = max(ans, maxu[x][i]);
            x = pp[x][i];
        }
    }
    ans = max(ans, maxu[x][0]);
    return ans;
}

void solv()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].d);
    }
    sort(b, b + m);
    for (int i = 0; i < m; ++i)
    {
        int x = b[i].x;
        int y = b[i].y;
        int d = b[i].d;
        if (fi(x) == fi(y))
            continue;
        c[i] = true;
        a[x].push_back(m_p(y, d));
        a[y].push_back(m_p(x, d));
        kpc(x, y);
    }
    dfs(1, 1, 0);
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        if (c[i])
            continue;
        int x = b[i].x;
        int y = b[i].y;
        int d = b[i].d;
        int maxu = max(go(x, y), go(y, x));
        if (maxu == d)
            ++ans;
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