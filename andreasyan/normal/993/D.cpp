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
const int N = 55;
const ll INF = 1000000009000006;

int n;
pair<int, int> a[N];

vector<pair<ll, vector<ll> > > vv;

ll dp[N][N];
void ubd(ll& x, ll y)
{
    x = max(x, y);
}
bool stg(ll t)
{
    if (t == 8334)
        printf("");
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < vv.size(); ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int q = 0; q <= sz(vv[i].se); ++q)
            {
                if (q > j)
                    continue;
                ll s = 0;
                for (int k = 0; k < sz(vv[i].se) - q; ++k)
                    s += (t * vv[i].se[k] - vv[i].fi);
                ubd(dp[i + 1][j - q + (sz(vv[i].se) - q)], dp[i][j] + s);
            }
        }
    }
    ll ans = -INF;
    for (int j = 0; j <= n; ++j)
        ans = max(ans, dp[sz(vv)][j]);
    return ans >= 0;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].fi);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].se);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    vector<ll> v;
    v.push_back(a[1].se);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].fi == a[i - 1].fi)
            v.push_back(a[i].se);
        else
        {
            vv.push_back(m_p(a[i - 1].fi, v));
            v = {a[i].se};
        }
    }
    vv.push_back(m_p(a[n].fi, v));

    for (int i = 0; i < sz(vv); ++i)
        vv[i].fi *= 1000;

    ll l = 0, r = INF;
    ll ans;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            stg(m);
            l = m + 1;
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
    solv();
    return 0;
}