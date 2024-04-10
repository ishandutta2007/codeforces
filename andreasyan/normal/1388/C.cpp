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

int n, m;
int p[N], h[N];
vector<int> g[N];

ll pp[N];

int p0[N];
void dfs0(int x, int p0)
{
    ::p0[x] = p0;
    pp[x] = p[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p0)
            continue;
        dfs0(h, x);
        pp[x] += pp[h];
    }
}

ll t[N], u[N];

void solv()
{
    cin >> n >> m;

    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
    }

    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs0(1, 1);
    for (int x = 1; x <= n; ++x)
    {
        if ((pp[x] + h[x]) % 2 != 0)
        {
            cout << "NO\n";
            return;
        }
        u[x] = (h[x] + pp[x]) / 2;
        t[x] = (pp[x] - h[x]) / 2;
        if (u[x] < 0 || t[x] < 0)
        {
            cout << "NO\n";
            return;
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        ll tt = 0;
        ll uu = 0;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == p0[x])
                continue;
            tt += t[h];
            uu += u[h];
        }

        ll U = h[x] - uu + tt + p[x];
        ll T = p[x] - h[x] + uu - tt;

        if (U % 2 != 0 && T % 2 != 0)
        {
            cout << "NO\n";
            return;
        }
        U /= 2;
        T /= 2;

        ll l = max(0LL, -T);
        ll r = min(tt, U);

        if (l > r)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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