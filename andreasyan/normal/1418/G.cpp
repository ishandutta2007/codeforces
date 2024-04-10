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
const int N = 500005;

pair<int, int> t[N * 4];
int laz[N * 4];

pair<int, int> mer(const pair<int, int>& l, const pair<int, int>& r)
{
    if (l.fi > r.fi)
        return l;
    if (l.fi < r.fi)
        return r;
    return m_p(l.fi, l.se + r.se);
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(0, 1);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void shi(int pos)
{
    t[pos * 2].fi += laz[pos];
    laz[pos * 2] += laz[pos];
    t[pos * 2 + 1].fi += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos].fi += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

int n;
int a[N];

vector<int> v[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    ll ans = 0;

    bil(1, n, 1);
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, i, i, n, 1);
        v[a[i]].push_back(i);
        int s = sz(v[a[i]]);
        if (s == 1)
        {
            ubd(1, n, 1, i, -1, 1);
        }
        else if (s == 2)
        {
            ubd(1, n, v[a[i]][s - 2] + 1, i, -1, 1);
        }
        else if (s == 3)
        {
            ubd(1, n, v[a[i]][s - 2] + 1, i, -1, 1);
            ubd(1, n, 1, v[a[i]][s - 3], 1, 1);
        }
        else if (s == 4)
        {
            ubd(1, n, v[a[i]][s - 2] + 1, i, -1, 1);
            ubd(1, n, 1, v[a[i]][s - 4], -1, 1);
            ubd(1, n, v[a[i]][s - 4] + 1, v[a[i]][s - 3], 1, 1);
        }
        else
        {
            ubd(1, n, v[a[i]][s - 2] + 1, i, -1, 1);
            ubd(1, n, v[a[i]][s - 5] + 1, v[a[i]][s - 4], -1, 1);
            ubd(1, n, v[a[i]][s - 4] + 1, v[a[i]][s - 3], 1, 1);
        }
        if (t[1].fi == n)
            ans += t[1].se;
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}