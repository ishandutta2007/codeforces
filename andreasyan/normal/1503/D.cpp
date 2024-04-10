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
const int N = 400005;

int n;
int aa[N], bb[N];

int u[N];
bool z[N];

pair<int, int> t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(y, x);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(0, 0);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

pair<int, int> t1[N * 4];
void ubd1(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t1[pos] = m_p(y, x);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd1(tl, m, x, y, pos * 2);
    else
        ubd1(m + 1, tr, x, y, pos * 2 + 1);
    t1[pos] = min(t1[pos * 2], t1[pos * 2 + 1]);
}

pair<int, int> qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(N, N);
    if (tl == l && tr == r)
        return t1[pos];
    int m = (tl + tr) / 2;
    return min(qry1(tl, m, l, min(m, r), pos * 2),
               qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int ans1, ans2;

int c[N];
void dfs(int x, int g)
{
    c[x] = g;
    ubd(1, n, x, 0, 1);
    ubd1(1, n, x, N, 1);
    if (g == 1 && z[x])
        ++ans1;
    if (g == 2 && !z[x])
        ++ans1;
    if (g == 1 && !z[x])
        ++ans2;
    if (g == 2 && z[x])
        ++ans2;
    while (1)
    {
        pair<int, int> h = qry(1, n, x, n, 1);
        if (h.fi < u[x])
            break;
        dfs(h.se, 3 - g);
    }
    while (1)
    {
        pair<int, int> h = qry1(1, n, 1, x, 1);
        if (h.fi > u[x])
            break;
        dfs(h.se, 3 - g);
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> aa[i] >> bb[i];

    for (int i = 1; i <= n; ++i)
    {
        if (aa[i] <= n && bb[i] <= n)
        {
            cout << "-1\n";
            return;
        }
        u[min(aa[i], bb[i])] = max(aa[i], bb[i]);
        if (aa[i] < bb[i])
            z[min(aa[i], bb[i])] = false;
        else
            z[min(aa[i], bb[i])] = true;
    }

    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, i, u[i], 1);
        ubd1(1, n, i, u[i], 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            ans1 = ans2 = 0;
            dfs(i, 1);
            ans += min(ans1, ans2);
        }
    }

    vector<pair<int, int> > v[3];
    for (int i = 1; i <= n; ++i)
        v[c[i]].push_back(m_p(i, u[i]));

    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j < v[i].size(); ++j)
        {
            if (v[i][j - 1].se < v[i][j].se)
            {
                cout << "-1\n";
                return;
            }
        }
    }

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