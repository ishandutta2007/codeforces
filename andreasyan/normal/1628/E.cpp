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

int n, qq;

vector<int> v[N];
vector<int> vk[N];

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y, int z)
{
    x = fi(x);
    y = fi(y);
    if (sz(v[x]) > sz(v[y]))
    {
        swap(v[x], v[y]);
        swap(vk[x], vk[y]);
    }

    vk[y].push_back(z);
    for (int i = 0; i < sz(v[x]); ++i)
    {
        v[y].push_back(v[x][i]);
    }
    for (int i = 0; i < sz(vk[x]); ++i)
    {
        vk[y].push_back(vk[x][i]);
    }
    p[x] = y;

    vector<int>().swap(v[x]);
    vector<int>().swap(vk[x]);
}

int u[N];
const int m = 19;
int maxu[N][m];
int uu[N];

int maxd(int x, int y)
{
    int l = u[x];
    int r = u[y];
    if (l > r)
        swap(l, r);
    ++l;
    if (l > r)
        return 0;
    return max(maxu[r][uu[r - l + 1]], maxu[l + (1 << uu[r - l + 1]) - 1][uu[r - l + 1]]);
}

int s[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        s[pos] = 0;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);

    s[pos] = max(s[pos * 2], s[pos * 2 + 1]);
    s[pos] = max(s[pos], maxd(tl, tr));
}

struct ban
{
    int x;
    int maxu;
    ban()
    {
        x = maxu = 0;
    }
    ban(int x, int maxu)
    {
        this->x = x;
        this->maxu = maxu;
    }
};

ban mer(const ban& a, const ban& b)
{
    if (a.x == 0)
        return b;
    if (b.x == 0)
        return a;
    return ban(a.x, max(max(a.maxu, b.maxu), maxd(a.x, b.x)));
}

ban t[N * 4];
char laz[N * 4];

void shi(int tl, int tr, int pos)
{
    if (laz[pos] == 0)
        return;
    if (laz[pos] == 1)
    {
        t[pos * 2] = ban(tl, s[pos * 2]);
        t[pos * 2 + 1] = ban(tr, s[pos * 2 + 1]);
    }
    else
    {
        t[pos * 2] = ban(0, 0);
        t[pos * 2 + 1] = ban(0, 0);
    }
    laz[pos * 2] = laz[pos * 2 + 1] = laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        laz[pos] = y;
        if (y == 1)
            t[pos] = ban(tl, s[pos]);
        else
            t[pos] = ban(0, 0);
        return;
    }
    shi(tl, tr, pos);

    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);

    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void solv()
{
    cin >> n >> qq;
    vector<pair<int, pair<int, int> > > b;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        b.push_back(m_p(z, m_p(x, y)));
    }

    for (int i = 1; i <= n; ++i)
    {
        v[i].push_back(i);
        p[i] = i;
    }

    sort(all(b));
    for (int i = 0; i < n - 1; ++i)
    {
        kpc(b[i].se.fi, b[i].se.se, b[i].fi);
    }

    for (int i = 0; i < n; ++i)
    {
        u[v[fi(1)][i]] = i;
    }

    for (int i = 1; i < n; ++i)
    {
        maxu[i][0] = vk[fi(1)][i - 1];
        for (int j = 1; i - (1 << j) + 1 >= 0; ++j)
        {
            maxu[i][j] = max(maxu[i][j - 1], maxu[i - (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        while ((1 << (uu[i] + 1)) <= i)
            ++uu[i];
    }

    bil(1, n, 1);

    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty <= 2)
        {
            int l, r;
            cin >> l >> r;
            ubd(1, n, l, r, ty, 1);
        }
        else
        {
            int x;
            cin >> x;

            if (t[1].x == 0)
                cout << "-1\n";
            else
            {
                int ans = max(t[1].maxu, maxd(t[1].x, x));
                if (ans == 0)
                    ans = -1;
                cout << ans << "\n";
            }
        }
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