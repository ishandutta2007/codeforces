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
const int N = 800006, M = 1000000000;

int z;
int ul[N * 30], ur[N * 30];
int laz[N * 30];
int minu[N * 30], maxu[N * 30];

void shi(int pos)
{
    if (laz[pos] == 0)
        return;

    minu[ul[pos]] += laz[pos];
    maxu[ul[pos]] += laz[pos];
    laz[ul[pos]] += laz[pos];

    minu[ur[pos]] += laz[pos];
    maxu[ur[pos]] += laz[pos];
    laz[ur[pos]] += laz[pos];

    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos] += y;
        maxu[pos] += y;
        laz[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;

    if (!ul[pos])
    {
        ul[pos] = ++z;
        minu[z] = tl;
        maxu[z] = m;
    }
    if (!ur[pos])
    {
        ur[pos] = ++z;
        minu[z] = m + 1;
        maxu[z] = tr;
    }

    shi(pos);

    ubd(tl, m, l, min(m, r), y, ul[pos]);
    ubd(m + 1, tr, max(m + 1, l), r, y, ur[pos]);

    minu[pos] = min(minu[ul[pos]], minu[ur[pos]]);
    maxu[pos] = max(maxu[ul[pos]], maxu[ur[pos]]);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return minu[pos];

    int m = (tl + tr) / 2;

    if (!ul[pos])
    {
        ul[pos] = ++z;
        minu[z] = tl;
        maxu[z] = m;
    }
    if (!ur[pos])
    {
        ur[pos] = ++z;
        minu[z] = m + 1;
        maxu[z] = tr;
    }

    shi(pos);

    if (x <= m)
        return qry(tl, m, x, ul[pos]);
    return qry(m + 1, tr, x, ur[pos]);
}

int qry1(int tl, int tr, int y, int pos)
{
    if (tl == tr)
    {
        if (minu[pos] < y)
            return tl;
        return -1;
    }

    int m = (tl + tr) / 2;

    if (!ul[pos])
    {
        ul[pos] = ++z;
        minu[z] = tl;
        maxu[z] = m;
    }
    if (!ur[pos])
    {
        ur[pos] = ++z;
        minu[z] = m + 1;
        maxu[z] = tr;
    }

    shi(pos);

    if (minu[ur[pos]] < y)
        return qry1(m + 1, tr, y, ur[pos]);
    return qry1(tl, m, y, ul[pos]);
}

int qry2(int tl, int tr, int y, int pos)
{
    if (tl == tr)
    {
        if (maxu[pos] > y)
            return tl;
        return M + 1;
    }

    int m = (tl + tr) / 2;

    if (!ul[pos])
    {
        ul[pos] = ++z;
        minu[z] = tl;
        maxu[z] = m;
    }
    if (!ur[pos])
    {
        ur[pos] = ++z;
        minu[z] = m + 1;
        maxu[z] = tr;
    }

    shi(pos);

    if (maxu[ul[pos]] > y)
        return qry2(tl, m, y, ul[pos]);
    return qry2(m + 1, tr, y, ur[pos]);
}

void solv()
{
    int n;
    cin >> n;

    ++z;
    minu[z] = 0;
    maxu[z] = M;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;

        int x1 = qry1(0, M, t, 1);
        int x2 = qry2(0, M, t, 1);

        ubd(0, M, 0, x1, 1, 1);
        ubd(0, M, x2, M, -1, 1);

        int qq;
        cin >> qq;
        while (qq--)
        {
            int x;
            cin >> x;
            x = (x + ans) % (M + 1);
            ans = qry(0, M, x, 1);
            cout << ans << "\n";
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