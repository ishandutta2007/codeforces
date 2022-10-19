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
const int N = 200005;

int n, k;
vector<int> g[N];

int p0[N];

vector<int> v;
int lv[N], rv[N];
int d[N];
void dfs(int x, int p)
{
    p0[x] = p;
    d[x] = d[p] + 1;
    lv[x] = sz(v);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
    }
    if (sz(g[x]) == 1 && x != p)
    {
        v.push_back(x);
    }
    rv[x] = sz(v) - 1;
}

pair<int, int> maxu[N * 4];
int laz[N * 4];

void shi(int pos)
{
    maxu[pos * 2].fi += laz[pos];
    laz[pos * 2] += laz[pos];
    maxu[pos * 2 + 1].fi += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = m_p(d[v[tl]], v[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        maxu[pos].fi += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

bool c[N];
void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    if (k >= sz(v))
    {
        ll ans = (n - sz(v)) * 1LL * sz(v);
        for (int i = sz(v); i <= k; ++i)
            ans = max(ans, (n - i) * 1LL * i);
        cout << ans << "\n";
        return;
    }

    bil(0, sz(v) - 1, 1);

    int r = 0, w = 0;

    while (k--)
    {
        int x = maxu[1].se;
        ++r;
        while (1)
        {
            if (c[x])
                break;
            c[x] = true;
            ++w;
            ubd(0, sz(v) - 1, lv[x], rv[x], -1, 1);
            x = p0[x];
        }
        --w;
    }

    int b = (n - r - w);

    ll ans = w * 1LL * (r - b);
    for (int i = 0; i <= b; ++i)
        ans = min(ans, (w + i) * 1LL * (r - (b - i)));

    cout << ans << "\n";
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