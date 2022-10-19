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
const int N = 200005;

int n, m;
ll a[N];
vector<int> g[N];

int c[N];
void dfs(int x)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
        {
            dfs(h);
            a[x] -= a[h];
            a[h] = 0;
        }
    }
}

void dfs1(int x, int cc)
{
    c[x] = cc;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!c[h])
            dfs1(h, 3 - cc);
    }
}

void solv()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i] -= x;
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    dfs(1);

    if (a[1] == 0)
    {
        cout << "YES\n";
        return;
    }

    if (a[1] % 2 != 0)
    {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    dfs1(1, 1);

    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (c[h] == c[x])
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
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