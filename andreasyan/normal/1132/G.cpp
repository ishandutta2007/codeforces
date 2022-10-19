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
const int N = 1000006;

int n, k;
int a[N];

int t[N * 4];
int laz[N * 4];

void shi(int pos)
{
    t[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    t[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubds(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        ubds(tl, m, x, y, pos * 2);
    else
        ubds(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qrys(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return n + 1;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return min(qrys(tl, m, l, min(m, r), pos * 2),
               qrys(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void ubd0(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd0(tl, m, x, y, pos * 2);
    else
        ubd0(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int qry0(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        return t[pos];
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry0(tl, m, x, pos * 2);
    else
        return qry0(m + 1, tr, x, pos * 2 + 1);
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int p[N];

vector<int> g[N];
int tin[N], tout[N], ti;
void dfs0(int x)
{
    tin[x] = ++ti;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs0(h);
    }
    tout[x] = ti;
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        ubds(1, n, i, n + 1, 1);

    for (int i = n; i >= 1; --i)
    {
        p[i] = qrys(1, n, a[i] + 1, n, 1);
        ubds(1, n, a[i], i, 1);
    }

    for (int i = 1; i <= n; ++i)
        g[p[i]].push_back(i);

    dfs0(n + 1);

    for (int i = 1; i <= n + 1; ++i)
        ubd0(1, n + 1, i, 0, 1);

    for (int i = n; i >= n - k + 1; --i)
    {
        ubd0(1, n + 1, tin[i], qry0(1, n + 1, tin[p[i]], 1) + 1, 1);
    }

    vector<int> ans;
    ans.push_back(t[1]);
    for (int i = n - k; i >= 1; --i)
    {
        ubd(1, n + 1, tin[i + k], tout[i + k], -1, 1);
        if (p[i] <= i + k - 1)
            ubd0(1, n + 1, tin[i], qry0(1, n + 1, tin[p[i]], 1) + 1, 1);
        else
            ubd0(1, n + 1, tin[i], 1, 1);
        ans.push_back(t[1]);
    }

    reverse(all(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}