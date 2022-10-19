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

int n, mm;
vector<int> a[N];

bool c[N];
const int m = 20;
int p[N][m];
int minu[N][m], maxu[N][m];
set<pair<int, int> > s;
int tin[N], tout[N], ti;
void dfs(int x, int p0)
{
    c[x] = true;
    tin[x] = ++ti;
    s.insert(m_p(p0, x));
    s.insert(m_p(x, p0));
    p[x][0] = p0;
    minu[x][0] = min(x, p0);
    maxu[x][0] = max(x, p0);
    for (int i = 1; i < m; ++i)
    {
        p[x][i] = p[p[x][i - 1]][i - 1];
        minu[x][i] = min(minu[x][i - 1], minu[p[x][i - 1]][i - 1]);
        maxu[x][i] = max(maxu[x][i - 1], maxu[p[x][i - 1]][i - 1]);
    }
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        if (!c[h])
            dfs(h, x);
    }
    tout[x] = ti;
}

bool isp(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

pair<int, int> go(int x, int y)
{
    if (isp(x, y))
        return m_p(N, -N);
    pair<int, int> ans = m_p(N, -N);
    for (int i = m - 1; i >= 0; --i)
    {
        if (!isp(p[x][i], y))
        {
            ans.fi = min(ans.fi, minu[x][i]);
            ans.se = max(ans.se, maxu[x][i]);
            x = p[x][i];
        }
    }
    ans.fi = min(ans.fi, minu[x][0]);
    ans.se = max(ans.se, maxu[x][0]);
    return ans;
}

int f[N];
ll fp[N];

int byn(int l0, int r0)
{
    int l = l0, r = r0;
    int ans = l0 - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (f[m] <= l0 - 1)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}

void solv()
{
    scanf("%d%d", &n, &mm);
    while (mm--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        dfs(i, i);
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int y = a[x][i];
            if (s.find(m_p(x, y)) == s.end())
            {
                pair<int, int> u = go(x, y);
                pair<int, int> u1 = go(y, x);
                u.fi = min(u.fi, u1.fi);
                u.se = max(u.se, u1.se);
                f[u.se] = max(f[u.se], u.fi);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        f[i] = max(f[i], f[i - 1]);
    for (int i = 1; i <= n; ++i)
        fp[i] = fp[i - 1] + f[i];
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int x = byn(l, r);
        ll ans = (l + r) * 1LL * (r - l + 1) / 2;
        ans -= (l - 1) * 1LL * (x - l + 1);
        ans -= (fp[r] - fp[x]);
        printf("%lld\n", ans);
    }
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