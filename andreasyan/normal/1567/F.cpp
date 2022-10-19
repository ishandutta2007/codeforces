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
const int N = 503;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

int n, m;
char a[N][N];
vector<pair<int, int> > g[N][N];

int c[N][N];
void dfs(int x, int y, int cc)
{
    c[x][y] = cc;
    for (int i = 0; i < g[x][y].size(); ++i)
    {
        pair<int, int> h = g[x][y][i];
        if (!c[h.fi][h.se])
            dfs(h.fi, h.se, 5 - cc);
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            if (a[x][y] == '.')
                continue;
            vector<pair<int, int> > v;
            for (int i = 0; i < 4; ++i)
            {
                int hx = x + xx[i];
                int hy = y + yy[i];
                if (a[hx][hy] == '.')
                    v.push_back(m_p(hx, hy));
            }

            if (sz(v) % 2 == 1)
            {
                cout << "NO\n";
                return;
            }

            for (int i = 0; i < sz(v); i += 2)
            {
                g[v[i].fi][v[i].se].push_back(v[i + 1]);
                g[v[i + 1].fi][v[i + 1].se].push_back(v[i]);
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            if (a[x][y] == '.' && !c[x][y])
            {
                dfs(x, y, 1);
            }
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            if (a[x][y] == 'X')
            {
                for (int i = 0; i < 4; ++i)
                {
                    int hx = x + xx[i];
                    int hy = y + yy[i];
                    if (a[hx][hy] == '.')
                        c[x][y] += c[hx][hy];
                }
                assert(c[x][y] % 5 == 0);
            }
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << c[i][j] << ' ';
        }
        cout << "\n";
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