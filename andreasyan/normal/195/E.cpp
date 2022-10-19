#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, M = 1000000007;

int n;
vector<pair<int, int> > a[N];
vector<int> b[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

bool c[N];

int tin[N], tout[N], ti;

void dfs(int x)
{
    c[x] = true;
    tin[x] = ++ti;
    for (int i = 0; i < b[x].size(); ++i)
    {
        int h = b[x][i];
        dfs(h);
    }
    tout[x] = ti;
}

int t[N];
void ubd(int x, int y)
{
    y = (y + M) % M;
    while (x <= n)
    {
        t[x] = (t[x] + y) % M;
        x += (x & (-x));
    }
}

int qry(int x)
{
    int ans = 0;
    while (x)
    {
        ans = (ans + t[x]) % M;
        x -= (x & (-x));
    }
    return ans;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= n; ++i)
    {
        int k;
        scanf("%d", &k);
        while (k--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i].push_back(m_p(x, y));
            b[i].push_back(fi(x));
            p[fi(x)] = i;
        }
    }
    for (int i = n; i >= 1; --i)
    {
        if (!c[i])
            dfs(i);
    }
    int ans = 0;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < a[x].size(); ++i)
        {
            int k = (qry(tin[a[x][i].first]) + (a[x][i].second + M) % M) % M;
            ans = (ans + k) % M;
            ubd(tin[b[x][i]], k);
            ubd(tout[b[x][i]] + 1, -k);
        }
    }
    printf("%d\n", ans);
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