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
vector<pair<int, int> > g[N];

int c[N];
void dfs(int x)
{
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (!c[h])
        {
            c[h] = 3 - c[x];
            dfs(h);
        }
    }
}

int q[N][3];
bool cc[N];

int ans[N];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int t, x, y;
        cin >> t >> x >> y;
        g[x].push_back(m_p(y, t));
        g[y].push_back(m_p(x, t));
    }

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            c[x] = 1;
            dfs(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i].fi;
            if (c[x] == c[h])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            ++q[x][g[x][i].se];
        }
    }

    set<pair<int, int> > s;
    for (int x = 1; x <= n; ++x)
    {
        s.insert(m_p(min(q[x][1], q[x][2]), x));
    }

    while (!s.empty())
    {
        int x = s.begin()->se;
        s.erase(s.begin());
        cc[x] = true;

        if (q[x][1] == 0)
        {
            if (c[x] == 1)
            {
                ans[x] = sz(s);
            }
            else
            {
                ans[x] = -sz(s);
            }
        }
        else if (q[x][2] == 0)
        {
            if (c[x] == 2)
            {
                ans[x] = sz(s);
            }
            else
            {
                ans[x] = -sz(s);
            }
        }
        else
        {
            cout << "NO\n";
            return;
        }

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i].fi;
            int t = g[x][i].se;
            if (cc[h])
                continue;
            s.erase(m_p(min(q[h][1], q[h][2]), h));
            --q[h][t];
            s.insert(m_p(min(q[h][1], q[h][2]), h));
        }
    }

    cout << "YES\n";
    for (int x = 1; x <= n; ++x)
    {
        if (c[x] == 1)
            cout << "L ";
        else
            cout << "R ";
        cout << ans[x] << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}