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
const int N = 100005;
struct ban
{
    int x, t;
};

int n;
ban a[N];
int v;

void ubd(int t[], int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(t, tl, m, x, y, pos * 2);
    else
        ubd(t, m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int t[], int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(t, tl, m, l, min(m, r), pos * 2),
               qry(t, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int t[N * 4];

int dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].t);
    scanf("%d", &v);

    vector<pair<ll, ll> > b;
    vector<ll> bs;
    for (int i = 1; i <= n; ++i)
    {
        b.push_back(m_p(a[i].x - a[i].t * 1LL * v, -a[i].x - a[i].t * 1LL * v));
        bs.push_back(b.back().se);
    }
    sort(all(bs));
    sort(all(b));
    reverse(all(b));
    for (int i = 0; i < n; ++i)
    {
        dp[i] = qry(t, 0, n, lower_bound(all(bs), b[i].se) - bs.begin(), n, 1) + 1;
        ubd(t, 0, n, lower_bound(all(bs), b[i].se) - bs.begin(), dp[i], 1);
    }
    int ans2 = 0;
    for (int i = 0; i < n; ++i)
        ans2 = max(ans2, dp[i]);

    memset(t, 0, sizeof t);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = qry(t, 0, n, lower_bound(all(bs), b[i].se) - bs.begin(), n, 1) + 1;
        if (dp[i] == 1)
            dp[i] = 0;
        if (dp[i] == 0)
        {
            ll x = (b[i].fi - b[i].se) / 2;
            ll t = (b[i].fi + b[i].se) / -2 / v;
            if (abs(x) <= t * v)
                dp[i] = 1;
        }
        ubd(t, 0, n, lower_bound(all(bs), b[i].se) - bs.begin(), dp[i], 1);
    }
    int ans1 = 0;
    for (int i = 0; i < n; ++i)
        ans1 = max(ans1, dp[i]);
    printf("%d %d\n", ans1, ans2);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}