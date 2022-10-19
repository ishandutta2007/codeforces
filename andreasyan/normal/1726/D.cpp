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
const int N = 200015;

int n, m;
vector<pair<int, int> > g[N];
pair<int, int> b[N];

bool c[N];
char ans[N];
void dfs(int x)
{
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        int hi = g[x][i].se;
        if (!c[h])
        {
            ans[hi] = '1';
            dfs(h);
        }
    }
}

vector<int> v;
bool dfs1(int x, int p, int y)
{
    v.push_back(x);
    if (x == y)
        return true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        int hi = g[x][i].se;
        if (h == p)
            continue;
        if (ans[hi] == '0')
            continue;
        if (dfs1(h, x, y))
            return true;
    }
    v.pop_back();
    return false;
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        c[i] = false;
    }
    for (int i = 0; i < m; ++i)
    {
        ans[i] = '0';
    }
    ans[m] = 0;

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(m_p(y, i));
        g[y].push_back(m_p(x, i));
        b[i] = m_p(x, y);
    }

    if (m == n - 1)
    {
        cout << ans << "\n";
        return;
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
        c[i] = false;
    int q = 0;
    for (int i = 0; i < m; ++i)
    {
        if (ans[i] == '0')
        {
            c[b[i].fi] = c[b[i].se] = true;
            ++q;
        }
    }
    for (int i = 1; i <= n; ++i)
        q -= c[i];

    if (q == 0)
    {
        for (int x = 1; x <= n; ++x)
        {
            if (c[x])
            {
                for (int i = 0; i < g[x].size(); ++i)
                {
                    int h = g[x][i].fi;
                    int hi = g[x][i].se;
                    if (c[h])
                    {
                        v.clear();
                        dfs1(x, x, h);
                        ans[hi] = '1';
                        break;
                    }
                }
                assert(sz(v) >= 3);

                bool z = false;
                for (int i = 0; i < g[x].size(); ++i)
                {
                    int h = g[x][i].fi;
                    int hi = g[x][i].se;
                    if (h == v[1])
                    {
                        ans[hi] = '0';
                        z = true;
                        break;
                    }
                }
                assert(z);
                break;
            }
        }
    }

    cout << ans << "\n";
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