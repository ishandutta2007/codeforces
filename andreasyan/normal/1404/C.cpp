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
const int N = 300005, S = 530;

int n, qq;
int a[N];

vector<pair<int, int> > v[N];

int ans[N];
int pans[N];

int maxu[N * 4];
int laz[N * 4];

void shi(int pos)
{
    maxu[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    maxu[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        maxu[pos]++;
        laz[pos]++;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

int qry0(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return -1;
    if (tl == l && tr == r)
    {
        if (maxu[pos] < y)
            return -1;
        if (tl == tr)
            return tl;
        shi(pos);
        int m = (tl + tr) / 2;
        int u = qry0(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
        if (u != -1)
            return u;
        return qry0(tl, m, l, min(m, r), y, pos * 2);
    }
    shi(pos);
    int m = (tl + tr) / 2;
    int u = qry0(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    if (u != -1)
        return u;
    return qry0(tl, m, l, min(m, r), y, pos * 2);
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return maxu[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2);
    return qry(m + 1, tr, x, pos * 2 + 1);
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < qq; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[n - y].push_back(m_p(x, i));

        /*int ans = 0;
        for (int i = 1 + x; i <= n - y; ++i)
        {
            if (0 <= i - a[i] && i - a[i] <= ans)
                ++ans;
        }
        printf("%d\n", ans);*/
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i - a[i] >= 0)
        {
            /*for (int x = 0; x < i; ++x)
            {
                if (i - a[i] <= ans[x])
                    ++ans[x];
            }*/
            ubd(0, n, 0, qry0(0, n, 0, i - 1, i - a[i], 1), 1);
        }
        for (int j = 0; j < v[i].size(); ++j)
        {
            //pans[v[i][j].se] = ans[v[i][j].fi];
            pans[v[i][j].se] = qry(0, n, v[i][j].fi, 1);
        }
    }

    for (int i = 0; i < qq; ++i)
        printf("%d\n", pans[i]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}