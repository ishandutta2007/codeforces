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

struct ban
{
    int ty;
    int x, y;
    ban()
    {
        ty = -1;
        x = y = -1;
    }
};

int n, q, k;
ban a[N];

vector<pair<int, int> > v[N * 4];
void ubd(int tl, int tr, int l, int r, pair<int, int> y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        v[pos].push_back(y);
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int p[N];
int s[N];

int fin(int x, vector<pair<int, int> >& up)
{
    if (x == p[x])
        return x;
    up.push_back(m_p(x, p[x]));
    return p[x] = fin(p[x], up);
}

void kpc(int x, int y, vector<pair<int, int> >& up, vector<pair<int, int> >& us)
{
    x = fin(x, up);
    y = fin(y, up);
    if (x == y)
        return;
    if (s[x] > s[y])
        swap(x, y);
    up.push_back(m_p(x, p[x]));
    p[x] = y;
    us.push_back(m_p(y, s[y]));
    s[y] += s[x];
}

int ans[N];
void rec(int tl, int tr, int pos)
{
    vector<pair<int, int> > up, us;
    for (int i = 0; i < sz(v[pos]); ++i)
    {
        kpc(v[pos][i].fi, v[pos][i].se, up, us);
    }
    if (tl == tr)
    {
        if (a[tl].ty == 2)
            ans[tl] = s[fin(a[tl].x, up)];
        reverse(all(up));
        reverse(all(us));
        for (int i = 0; i < sz(up); ++i)
            p[up[i].fi] = up[i].se;
        for (int i = 0; i < sz(us); ++i)
            s[us[i].fi] = us[i].se;
        return;
    }
    int m = (tl + tr) / 2;
    rec(tl, m, pos * 2);
    rec(m + 1, tr, pos * 2 + 1);
    reverse(all(up));
    reverse(all(us));
    for (int i = 0; i < sz(up); ++i)
        p[up[i].fi] = up[i].se;
    for (int i = 0; i < sz(us); ++i)
        s[us[i].fi] = us[i].se;
}

void solv()
{
    scanf("%d%d%d", &n, &q, &k);
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d", &a[i].ty);
        if (a[i].ty == 1)
            scanf("%d%d", &a[i].x, &a[i].y);
        else if (a[i].ty == 2)
            scanf("%d", &a[i].x);
    }
    vector<int> v;
    for (int i = 1; i <= q; ++i)
    {
        if (a[i].ty == 3)
            v.push_back(i);
    }
    for (int i = 1; i <= q; ++i)
    {
        if (a[i].ty == 1)
        {
            int u = upper_bound(all(v), i) - v.begin();
            if (u + k - 1 >= sz(v))
            {
                ubd(1, q, i, q, m_p(a[i].x, a[i].y), 1);
            }
            else
            {
                ubd(1, q, i, v[u + k - 1], m_p(a[i].x, a[i].y), 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        s[i] = 1;
    }
    rec(1, q, 1);
    for (int i = 1; i <= q; ++i)
    {
        if (a[i].ty == 2)
            printf("%d\n", ans[i]);
    }
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