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
const int N = 5003;

int u[N];

int hq;
int hh[N];

int t[N][700];
void pre()
{
    u[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        hh[i] = ++hq;
        for (int j = i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            int x = j;
            while (x > 1)
            {
                ++t[i][hh[u[x]]];
                x /= u[x];
            }
        }
    }
}

int nn;
int a[N];

int z;
map<int, int> g[N * 700];
int e[N * 700];

ll pans;
ll ans;
void dfs(int x, int s, ll mans)
{
    for (auto it = g[x].begin(); it != g[x].end(); ++it)
    {
        mans += e[it->se] * 1LL * s;
    }

    if (g[x].empty())
    {
        mans += e[x] * 1LL * s;
        ans = min(ans, s * 1LL * nn + pans - 2 * mans);
        return;
    }

    int q = 0;
    for (auto it = g[x].begin(); it != g[x].end(); ++it)
        q += e[it->se];

    int nx = 0;
    for (auto it = g[x].begin(); it != g[x].end(); ++it)
    {
        int u = it->fi - nx;
        ans = min(ans, (s + nx + u) * 1LL * nn + pans - 2 * (mans + u * 1LL * q));
        ans = min(ans, (s + nx) * 1LL * nn + pans - 2 * mans);
        nx = it->fi;

        q -= e[it->se];
        mans -= e[it->se] * 1LL * s;
        dfs(it->se, s + it->fi, mans + q * 1LL * it->fi);
        mans += e[it->se] * 1LL * s;
        mans += e[it->se] * 1LL * it->fi;
    }
}

void solv()
{
    cin >> nn;
    for (int ii = 0; ii < nn; ++ii)
    {
        int k;
        cin >> k;
        ++a[k];
    }

    pans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (!a[i])
            continue;

        for (int j = 1; j <= hq; ++j)
            pans += a[i] * 1LL * t[i][j];

        int pos = 0;
        for (int j = hq; j >= 1; --j)
        {
            if (g[pos].find(t[i][j]) == g[pos].end())
                g[pos][t[i][j]] = ++z;
            pos = g[pos][t[i][j]];
            e[pos] += a[i];
        }
    }

    ans = 1000000009000000009;
    dfs(0, 0, 0);

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}