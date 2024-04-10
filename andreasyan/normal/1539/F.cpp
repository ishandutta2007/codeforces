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
int a[N];

struct ban
{
    int l, r, s;
    ban()
    {
        l = r = s = 0;
    }
    ban(int x)
    {
        if (x == 0 || x == 1)
        {
            l = r = s = 1;
        }
        else
        {
            l = r = 0;
            s = -1;
        }
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.s = l.s + r.s;
    res.l = max(l.l, l.s + r.l);
    res.r = max(r.r, r.s + l.r);
    return res;
}

void ubd(vector<ban>& t, int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(t, tl, m, x, y, pos * 2);
    else
        ubd(t, m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(vector<ban>& t, int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(t, tl, m, l, min(m, r), pos * 2),
               qry(t, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

vector<ban> t1, t2;

vector<int> v[N];

int ans[N];

int qryy(int i)
{
    int d = qry(t1, 1, n, 1, i - 1, 1).r + 1 + qry(t1, 1, n, i + 1, n, 1).l;
    int ans = (d + 2) / 2 - 1;
    d = qry(t2, 1, n, 1, i - 1, 1).r + 1 + qry(t2, 1, n, i + 1, n, 1).l;
    ans = max(ans, d - (d + 2) / 2);
    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        v[a[i]].push_back(i);

    t1.assign(n * 4 + 5, ban());
    t2.assign(n * 4 + 5, ban());

    for (int j = 0; j < sz(v[1]); ++j)
    {
        ubd(t1, 1, n, v[1][j], 0, 1);
        ubd(t2, 1, n, v[1][j], 0, 1);
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            ubd(t1, 1, n, v[i][j], 1, 1);
            ubd(t2, 1, n, v[i][j], -1, 1);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            ans[v[i][j]] = qryy(v[i][j]);
        }

        for (int j = 0; j < sz(v[i]); ++j)
        {
            ubd(t1, 1, n, v[i][j], -1, 1);
            ubd(t2, 1, n, v[i][j], 1, 1);
        }
        for (int j = 0; j < sz(v[i + 1]); ++j)
        {
            ubd(t1, 1, n, v[i + 1][j], 0, 1);
            ubd(t2, 1, n, v[i + 1][j], 0, 1);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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