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

int n, m, q;
pair<int, int> a[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

bool stg(int qq)
{
    vector<pair<pair<int, int>, int> > v;
    for (int i = 1; i <= qq; ++i)
    {
        int x = (a[i].fi + 1) / 2;
        int y = (a[i].se + 1) / 2;
        v.push_back(m_p(m_p(x, y), 1 - a[i].fi % 2));
    }
    sort(all(v));
    memset(t, 0, sizeof t);
    for (int i = 0; i < sz(v); ++i)
    {
        int x = v[i].fi.fi;
        int y = v[i].fi.se;
        if (v[i].se == 0)
        {
            ubd(1, m, y, 1);
        }
        else
        {
            if (qry(1, m, 1, y, 1))
                return false;
        }
    }
    return true;
}

void solv()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d%d", &a[i].fi, &a[i].se);
    }

    int ans = 0;
    int l = 1, r = q;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    for (int i = 1; i <= ans; ++i)
        printf("YES\n");
    for (int i = ans + 1; i <= q; ++i)
        printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    tt = 1;
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}