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
const int N = 200005, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int b[N];
void pre()
{
    b[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (b[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!b[j])
                b[j] = i;
        }
    }
}

int n;
int a[N];

vector<pair<int, int> > v[N], u[N];

int t[N * 125];
int z;
int ul[N * 125], ur[N * 125];

int ubd(int tl, int tr, int x, int y, int pos)
{
    int ypos = ++z;
    t[ypos] = (t[pos] * 1LL * y) % M;
    ul[ypos] = ul[pos];
    ur[ypos] = ur[pos];
    if (tl == tr)
        return ypos;
    int m = (tl + tr) / 2;
    if (x <= m)
        ul[ypos] = ubd(tl, m, x, y, ul[pos]);
    else
        ur[ypos] = ubd(m + 1, tr, x, y, ur[pos]);
    return ypos;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 1;
    if (pos == 0)
        return t[pos];
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), ul[pos]) * 1LL *
            qry(m + 1, tr, max(m + 1, l), r, ur[pos])) % M;
}

int root[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = rnf() % 200000 + 1;
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        vector<pair<int, int> > v;
        while (x > 1)
        {
            if (v.empty() || v.back().fi != b[x])
                v.push_back(m_p(b[x], 1));
            else
                v.back().se++;
            x /= b[x];
        }

        for (int j = 0; j < sz(v); ++j)
            ::v[v[j].fi].push_back(m_p(i, v[j].se));
    }

    for (int x = 0; x < N; ++x)
    {
        if (v[x].empty())
            continue;

        stack<int> s;
        for (int i = 0; i < sz(v[x]); ++i)
        {
            while (!s.empty() && v[x][s.top()].se < v[x][i].se)
            {
                pair<int, int> t = v[x][s.top()];
                s.pop();

                t.se = ast(x, t.se);
                u[v[x][i].fi].push_back(m_p(t.fi, ast(t.se, M - 2)));
                if (!s.empty())
                {
                    u[v[x][i].fi].push_back(m_p(v[x][s.top()].fi, t.se));
                }
            }

            u[v[x][i].fi].push_back(m_p(v[x][i].fi, ast(x, v[x][i].se)));
            if (!s.empty())
                u[v[x][i].fi].push_back(m_p(v[x][s.top()].fi, ast(ast(x, v[x][i].se), M - 2)));
            s.push(i);
        }
    }

    t[z] = 1;
    for (int i = 1; i <= n; ++i)
    {
        root[i] = root[i - 1];
        sort(all(u[i]));
        for (int j = 0; j < sz(u[i]); ++j)
        {
            if (j == sz(u[i]) - 1 || u[i][j].fi != u[i][j + 1].fi)
                root[i] = ubd(1, n, u[i][j].fi, u[i][j].se, root[i]);
            else
                u[i][j + 1].se = (u[i][j + 1].se * 1LL * u[i][j].se) % M;
        }
    }

    int ans = 0;
    int qq;
    cin >> qq;
    while (qq--)
    {
        int l, r;
        l = rnf() % n;
        r = rnf() % n;
        cin >> l >> r;
        l = (l + ans) % n + 1;
        r = (r + ans) % n + 1;
        if (l > r)
            swap(l, r);
        ans = qry(1, n, l, r, root[r]);
        cout << ans << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}