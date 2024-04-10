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
const int N = 1000006, nn = 1000000;

ll ans;

int n, m;
vector<pair<int, int> > v[N];
vector<int> v1[N], v2[N];

int t[N * 4];
void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2) + t[pos];
    return qry(m + 1, tr, x, pos * 2 + 1) + t[pos];
}

void solv()
{
    ans = 1;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        int y;
        int l, r;
        scanf("%d%d%d", &y, &l, &r);
        if (l == 0 && r == nn)
            ++ans;
        v[y].push_back(m_p(l, r));
    }
    for (int i = 0; i < m; ++i)
    {
        int x;
        int l, r;
        scanf("%d%d%d", &x, &l, &r);
        if (l == 0 && r == nn)
            ++ans;
        if (l == 0)
            v1[r].push_back(x);
        else
            v2[l].push_back(x);
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            ubd(0, nn, v[i][j].fi, v[i][j].se, 1);
        }
        for (int j = 0; j < sz(v1[i]); ++j)
        {
            ans += qry(0, nn, v1[i][j], 1);
        }
    }

    memset(t, 0, sizeof t);
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            ubd(0, nn, v[i][j].fi, v[i][j].se, 1);
        }
        for (int j = 0; j < sz(v2[i]); ++j)
        {
            ans += qry(0, nn, v2[i][j], 1);
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}