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
const int N = 200005, M = 10004, MM = 10000;
const ll INF = 1000000009000000009;

int n, m, k;
vector<pair<int, int> > v[2][2];

vector<ll> p[2][2];

int q[M * 4];
ll s[M * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        q[pos] += y;
        s[pos] += x * y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    q[pos] = q[pos * 2] + q[pos * 2 + 1];
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
}

ll qry(int tl, int tr, int y, int pos)
{
    if (tl == tr)
    {
        return y * tl;
    }
    int m = (tl + tr) / 2;
    if (q[pos * 2] >= y)
        return qry(tl, m, y, pos * 2);
    return s[pos * 2] + qry(m + 1, tr, y - q[pos * 2], pos * 2 + 1);
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        v[a][b].push_back(m_p(t, i));
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (v[i][j].empty())
                continue;
            sort(all(v[i][j]));
            p[i][j].assign(v[i][j].size(), 0);
            p[i][j][0] = v[i][j][0].fi;
            for (int k = 1; k < v[i][j].size(); ++k)
                p[i][j][k] = p[i][j][k - 1] + v[i][j][k].fi;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (i == 1 && j == 1)
                continue;
            for (int k = 0; k < v[i][j].size(); ++k)
                ubd(1, MM, v[i][j][k].fi, 1, 1);
        }
    }
    int i = 0, j = 0;

    int ansq;
    ll ans = INF;
    for (int q = 0; q <= min(sz(v[1][1]), m); ++q)
    {
        ll yans = 0;

        if (q > 0)
            yans += p[1][1][q - 1];
        if (sz(v[1][0]) < (k - q))
            continue;
        if ((k - q) > 0)
            yans += p[1][0][(k - q) - 1];
        if (sz(v[0][1]) < (k - q))
            continue;
        if ((k - q) > 0)
            yans += p[0][1][(k - q) - 1];

        int mm = m;
        mm -= q;
        if ((k - q) > 0)
            mm -= (k - q);
        if ((k - q) > 0)
            mm -= (k - q);
        if (mm < 0)
            continue;

        while (i < sz(v[1][0]) && i <= (k - q) - 1)
        {
            ubd(1, MM, v[1][0][i].fi, -1, 1);
            ++i;
        }
        while (i > 0 && i > (k - q))
        {
            --i;
            ubd(1, MM, v[1][0][i].fi, 1, 1);
        }

        while (j < sz(v[0][1]) && j <= (k - q) - 1)
        {
            ubd(1, MM, v[0][1][j].fi, -1, 1);
            ++j;
        }
        while (j > 0 && j > (k - q))
        {
            --j;
            ubd(1, MM, v[0][1][j].fi, 1, 1);
        }

        if (mm > ::q[1])
            continue;

        yans += qry(1, MM, mm, 1);
        if (yans < ans)
        {
            ans = yans;
            ansq = q;
        }
    }
    if (ans == INF)
    {
        printf("-1\n");
        return;
    }
    printf("%lld\n", ans);

    int q = ansq;

    vector<int> ansv;

    vector<pair<int, int> > mn = v[0][0];

    for (int i = 0; i < sz(v[1][1]); ++i)
    {
        if (i < q)
            ansv.push_back(v[1][1][i].se);
        else
            mn.push_back(v[1][1][i]);
    }

    for (int i = 0; i < sz(v[1][0]); ++i)
    {
        if (i < (k - q))
            ansv.push_back(v[1][0][i].se);
        else
            mn.push_back(v[1][0][i]);
    }

    for (int i = 0; i < sz(v[0][1]); ++i)
    {
        if (i < (k - q))
            ansv.push_back(v[0][1][i].se);
        else
            mn.push_back(v[0][1][i]);
    }

    int mm = m;
    mm -= q;
    if ((k - q) > 0)
        mm -= (k - q);
    if ((k - q) > 0)
        mm -= (k - q);

    sort(all(mn));
    for (int i = 0; i < mm; ++i)
        ansv.push_back(mn[i].se);

    for (int i = 0; i < m; ++i)
        printf("%d ", ansv[i]);
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