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
vector<pair<int, int> > g[N];

int c[30][N];

int k;
void dfs(int j, int x)
{
    c[j][x] = k;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if ((g[x][i].se & (1 << j)) && !c[j][h])
            dfs(j, h);
    }
}

bool cc[30][N];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }

    for (int j = 0; j < 30; ++j)
    {
        k = 0;
        for (int x = 1; x <= n; ++x)
        {
            if (!c[j][x])
            {
                ++k;
                dfs(j, x);
            }
        }

        for (int x = 1; x <= n; ++x)
        {
            for (int i = 0; i < g[x].size(); ++i)
            {
                if (g[x][i].se % 2 == 0)
                {
                    cc[j][c[j][x]] = true;
                    break;
                }
            }

        }
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x, y;
        cin >> x >> y;

        bool z = false;
        for (int j = 0; j < 30; ++j)
        {
            if (c[j][x] == c[j][y])
            {
                z = true;
                break;
            }
        }

        if (z)
        {
            cout << "0\n";
            continue;
        }

        for (int j = 1; j < 30; ++j)
        {
            if (cc[j][c[j][x]])
            {
                z = true;
                break;
            }
        }

        if (z)
            cout << "1\n";
        else
            cout << "2\n";
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