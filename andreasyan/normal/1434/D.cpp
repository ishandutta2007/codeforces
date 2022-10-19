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
const int N = 500005;

int n;
vector<int> g[N], gg[N], gi[N];

int d[N];
void dfs0(int x, int p)
{
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
    }
}

int a[N];
int tin[N], tout[N], ti;
int rtin[N];
int uu[N];
void dfs1(int x, int p)
{
    tin[x] = ++ti;
    rtin[tin[x]] = x;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        a[h] = (a[x] ^ gg[x][i]);
        uu[gi[x][i]] = h;
        dfs1(h, x);
    }
    tout[x] = ti;
}

int d1[N], d2[N];

struct ban
{
    int d10, d11;
    int d20, d21;
    ban()
    {
        d10 = d11 = d20 = d21 = 0;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.d10 = max(l.d10, r.d10);
    res.d11 = max(l.d11, r.d11);
    res.d20 = max(l.d20, r.d20);
    res.d21 = max(l.d21, r.d21);
    return res;
}

ban t[N * 4];
bool laz[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        int x = rtin[tl];
        if (a[x] == 0)
        {
            t[pos].d10 = d1[x];
            t[pos].d20 = d2[x];
        }
        else
        {
            t[pos].d11 = d1[x];
            t[pos].d21 = d2[x];
        }
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void shii(int pos)
{
    swap(t[pos].d10, t[pos].d11);
    swap(t[pos].d20, t[pos].d21);
    laz[pos] ^= true;
}

void shi(int pos)
{
    if (!laz[pos])
        return;
    shii(pos * 2);
    shii(pos * 2 + 1);
    laz[pos] = false;
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        shii(pos);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(y);
        g[y].push_back(x);
        gg[x].push_back(z);
        gg[y].push_back(z);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    dfs0(1, 1);
    int x1 = 1;
    for (int x = 1; x <= n; ++x)
    {
        if (d[x] > d[x1])
            x1 = x;
    }

    dfs0(x1, x1);
    int x2 = 1;
    for (int x = 1; x <= n; ++x)
    {
        if (d[x] > d[x2])
            x2 = x;
    }

    for (int x = 1; x <= n; ++x)
        d1[x] = d[x];
    dfs0(x2, x2);
    for (int x = 1; x <= n; ++x)
        d2[x] = d[x];

    dfs1(1, 1);
    bil(1, n, 1);

    int qq;
    cin >> qq;
    while (qq--)
    {
        int i;
        cin >> i;

        ubd(1, n, tin[uu[i]], tout[uu[i]], 1);
        if (tin[uu[i]] <= tin[x1] && tin[x1] <= tout[uu[i]])
            a[x1] ^= 1;
        if (tin[uu[i]] <= tin[x2] && tin[x2] <= tout[uu[i]])
            a[x2] ^= 1;

        int ans = 0;
        if (a[x1] == 0)
            ans = max(ans, t[1].d10);
        else
            ans = max(ans, t[1].d11);
        if (a[x2] == 0)
            ans = max(ans, t[1].d20);
        else
            ans = max(ans, t[1].d21);

        cout << ans << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}