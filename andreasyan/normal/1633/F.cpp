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

int n;
vector<int> g[N];

int q[N];
void dfsp(int x)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfsp(h);
        q[x] ^= q[h];
    }
}

void por()
{
    n = (rnf() % 7) * 2 + 2;
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 2; i <= n; ++i)
    {
        g[(rnf() % (i - 1)) + 1].push_back(i);
    }

    dfsp(1);

    int qq = 0;
    for (int x = 1; x <= n; ++x)
        qq += q[x];

    if (qq == n / 2)
    {
        for (int x = 1; x <= n; ++x)
        {
            int qq = 0;
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                qq += q[h];
            }
            assert(qq <= 1);
        }
    }
}

vector<int> gi[N];

int p0[N];
int ui[N];
void dfs0(int x, int p)
{
    p0[x] = p;

    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        q[x] += q[h];
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
        {
            ui[x] = gi[x][i];
            swap(g[x][i], g[x].back());
            swap(gi[x][i], gi[x].back());
            break;
        }
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (q[h] > q[g[x][0]])
        {
            swap(g[x][i], g[x][0]);
            swap(gi[x][i], gi[x][0]);
        }
    }
}

int f[N];
int tin[N], tout[N], ti;
int rtin[N];
void dfs1(int x, int p)
{
    tin[x] = ++ti;
    rtin[tin[x]] = x;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (i == 0)
        {
            f[h] = f[x];
            dfs1(h, x);
        }
        else
        {
            f[h] = h;
            dfs1(h, x);
        }
    }
    tout[x] = ti;
}

bool laz[N * 4];
ll s0[N * 4], s1[N * 4];
int q0[N * 4], q1[N * 4];
void bil(int tl, int tr, int pos)
{
    laz[pos] = false;
    if (tl == tr)
    {
        s0[pos] = ui[rtin[tl]];
        s1[pos] = 0;
        q0[pos] = 1;
        q1[pos] = 0;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    s0[pos] = s0[pos * 2] + s0[pos * 2 + 1];
    s1[pos] = s1[pos * 2] + s1[pos * 2 + 1];
    q0[pos] = q0[pos * 2] + q0[pos * 2 + 1];
    q1[pos] = q1[pos * 2] + q1[pos * 2 + 1];
}

void ave(int pos)
{
    laz[pos] ^= true;
    swap(s0[pos], s1[pos]);
    swap(q0[pos], q1[pos]);
}

void shi(int pos)
{
    if (!laz[pos])
        return;

    ave(pos * 2);
    ave(pos * 2 + 1);
    laz[pos] = false;
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        ave(pos);
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    s0[pos] = s0[pos * 2] + s0[pos * 2 + 1];
    s1[pos] = s1[pos * 2] + s1[pos * 2 + 1];
    q0[pos] = q0[pos * 2] + q0[pos * 2 + 1];
    q1[pos] = q1[pos * 2] + q1[pos * 2 + 1];
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return q1[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2);
    return qry(m + 1, tr, x, pos * 2 + 1);
}

void ubd(int x)
{
    while (1)
    {
        ubd(1, n, tin[f[x]], tin[x], 1);
        if (f[x] == 1)
            return;
        x = p0[f[x]];
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    dfs0(1, 1);
    f[1] = 1;
    dfs1(1, 1);

    bil(1, n, 1);

    vector<int> v;
    ubd(1);
    v.push_back(1);
    while (1)
    {
        int ty;
        cin >> ty;

        if (ty == 1)
        {
            int x;
            cin >> x;
            ubd(x);
            v.push_back(x);

            if (sz(v) % 2 == 0 && q1[1] == sz(v) / 2)
            {
                cout << s1[1] << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (ty == 2)
        {
            if (sz(v) % 2 == 0 && q1[1] == sz(v) / 2)
            {
                vector<int> ans;
                for (int i = 0; i < sz(v); ++i)
                {
                    if (qry(1, n, tin[v[i]], 1))
                        ans.push_back(ui[v[i]]);
                }
                sort(all(ans));

                assert(sz(ans) == sz(v) / 2);
                cout << sz(ans) << ' ';
                for (int i = 0; i < sz(ans); ++i)
                    cout << ans[i] << ' ';
                cout << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (ty == 3)
            break;
        else
            assert(false);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int pt = 100000;
    while (pt--)
    {
        por();
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}