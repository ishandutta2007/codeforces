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

int n, m;
vector<int> g[N];

vector<int> gg[N];

set<int> s;
void dfs(int x)
{
    s.erase(x);
    for (int i = 0; i < sz(g[x]) - 1; ++i)
    {
        while (1)
        {
            auto it = s.upper_bound(g[x][i]);
            if (it == s.end())
                break;
            if (*it >= g[x][i + 1])
                break;
            gg[x].push_back(*it);
            gg[*it].push_back(x);
            dfs(*it);
        }
    }
}

bool c[N];
bool z[N];
vector<int> f[N];
void dfs1(int x, int p)
{
    c[x] = true;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        if (!z[h])
        {
            z[x] = true;
            f[x].push_back(h);
        }
    }
}

int ans1[N], ans2[N];

void solv()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        gg[i].clear();
        f[i].clear();
        c[i] = false;
        z[i] = false;
        ans1[i] = ans2[i] = 0;
    }
    s.clear();

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int x = 1; x <= n; ++x)
    {
        g[x].push_back(0);
        g[x].push_back(n + 1);
        sort(all(g[x]));
    }

    for (int x = 1; x <= n; ++x)
        s.insert(x);

    for (int x = 1; x <= n; ++x)
    {
        if (s.find(x) != s.end())
            dfs(x);
    }

    int k = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            continue;
        dfs1(x, x);

        if (gg[x].empty())
        {
            ans1[x] = ans2[x] = ++k;
        }
        else
        {
            if (!z[x])
            {
                assert(z[gg[x][0]]);
                f[gg[x][0]].push_back(x);
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (z[x])
        {
            ans1[x] = k + sz(f[x]) + 1;
            ans2[x] = k + 1;
            for (int i = 0; i < f[x].size(); ++i)
            {
                int h = f[x][i];
                ans1[h] = k + i + 1;
                ans2[h] = k + i + 2;
            }
            k += (sz(f[x]) + 1);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans1[i] << ' ';
    cout << "\n";
    for (int i = 1; i <= n; ++i)
        cout << ans2[i] << ' ';
    cout << "\n";
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