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
const ll INF = 1000000009000000009;

int n, m, k;
int x[N];
int a[N], b[N], c[N], d[N], h[N];

vector<int> v[N];
vector<pair<int, ll> > vv[N];

bool so(int i, int j)
{
    return b[i] < b[j];
}

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    for (int i = 1; i <= k; ++i)
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> h[i];

    for (int i = 1; i <= n; ++i)
    {
        v[i].clear();
        vv[i].clear();
    }

    for (int i = 1; i <= k; ++i)
        v[a[i]].push_back(i);

    vv[1].push_back(m_p(1, 0));
    for (int i = 1; i < n; ++i)
    {
        sort(all(vv[i]));
        sort(all(v[i]), so);

        int t = -1;
        ll y = -INF;
        int u = 0;
        for (int j = 0; j < sz(v[i]); ++j)
        {
            while (t + 1 < sz(vv[i]) && vv[i][t + 1].fi <= b[v[i][j]])
            {
                ++t;
                y -= (vv[i][t].fi - u) * 1LL * x[i];
                u = vv[i][t].fi;
                y = max(y, vv[i][t].se);
            }
            y -= (b[v[i][j]] - u) * 1LL * x[i];
            u = b[v[i][j]];
            if (y > -INF)
                vv[c[v[i][j]]].push_back(m_p(d[v[i][j]], y + h[v[i][j]]));
        }

        reverse(all(vv[i]));
        t = -1;
        y = -INF;
        u = m + 1;
        for (int j = sz(v[i]) - 1; j >= 0; --j)
        {
            while (t + 1 < sz(vv[i]) && vv[i][t + 1].fi >= b[v[i][j]])
            {
                ++t;
                y -= (u - vv[i][t].fi) * 1LL * x[i];
                u = vv[i][t].fi;
                y = max(y, vv[i][t].se);
            }
            y -= (u - b[v[i][j]]) * 1LL * x[i];
            u = b[v[i][j]];
            if (y > -INF)
                vv[c[v[i][j]]].push_back(m_p(d[v[i][j]], y + h[v[i][j]]));
        }
    }

    ll ans = -INF;
    for (int i = 0; i < sz(vv[n]); ++i)
        ans = max(ans, vv[n][i].se - (m - vv[n][i].fi) * 1LL * x[n]);

    if (ans == -INF)
        cout << "NO ESCAPE\n";
    else
        cout << -ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}