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

int n, m;
int a[N];
vector<pair<int, int> > v[N];

ll maxu[N * 4];
ll laz[N * 4];

void shi(int pos)
{
    if (!laz[pos])
        return;
    maxu[pos * 2] += laz[pos];
    maxu[pos * 2 + 1] += laz[pos];
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        maxu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

ll dp[N];

void clr()
{
    for (int i = 0; i < 1000; ++i)
    {
        v[i].clear();
        maxu[i] = 0;
        laz[i] = 0;
    }
}

void kar()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
    {
        int l, r, p;
        scanf("%d%d%d", &l, &r, &p);
        v[r].push_back(m_p(l, p));
    }
}

pair<pair<int, int>, int> b[N];

void gen()
{
    n = 7;
    m = 7;
    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 1000000000 + 1;
    for (int i = 0; i < m; ++i)
    {
        int l, r, p;
        l = rnf() % n + 1;
        r = rnf() % n + 1;
        p = rnf() % 1000000000 + 1;
        if (l > r)
            swap(l, r);
        v[r].push_back(m_p(l, p));
        b[i] = m_p(m_p(l, r), p);
    }
}

void solv()
{
    clr();
    //gen();
    kar();
    for (int i = 1; i <= n; ++i)
    {
        ubd(0, n, 0, i - 1, -a[i], 1);
        for (int j = 0; j < v[i].size(); ++j)
        {
            ubd(0, n, 0, v[i][j].fi - 1, v[i][j].se, 1);
        }
        dp[i] = maxu[1];
        dp[i] = max(dp[i], dp[i - 1]);
        ubd(0, n, i, i, dp[i], 1);
    }
    /*ll ans = 0;
    int ansx = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        ll yans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (i - 1))))
            {
                yans -= a[i];
            }
        }
        for (int r = 1; r <= n; ++r)
        {
            for (int j = 0; j < v[r].size(); ++j)
            {
                int l = v[r][j].fi;
                int p = v[r][j].se;
                bool z = true;
                for (int i = l; i <= r; ++i)
                {
                    if (!(x & (1 << (i - 1))))
                    {
                        z = false;
                        break;
                    }
                }
                if (z)
                    yans += p;
            }
        }
        if (yans > ans)
        {
            ans = yans;
            ansx = x;
        }
    }*/
    /*if (dp[n] != ans)
    {
        printf("WA\n");
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n; ++i)
            printf("%d ", a[i]);
        printf("\n");
        for (int i = 0; i < m; ++i)
            printf("%d %d %d\n", b[i].fi.fi, b[i].fi.se, b[i].se);
        exit(0);
    }*/
    /*for (int i = 0; i < n; ++i)
    {
        if ((ansx & (1 << i)))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    printf("%lld\n", ans);*/
    printf("%lld\n", dp[n]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}