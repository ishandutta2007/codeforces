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
const int N = 505;

int n, m;
char a[N][N];
int b[N][N];

vector<int> g[N];

int u[N];
bool c[N];

bool dfs(int x)
{
    if (c[x] == true)
        return false;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!u[h])
        {
            u[h] = x;
            return true;
        }
        else
        {
            if (dfs(u[h]))
            {
                u[h] = x;
                return true;
            }
        }
    }
    return false;
}


void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'B')
            {
                b[i][j] ^= 1;
                b[i - 1][j] ^= 1;
                b[i][j - 1] ^= 1;
                b[i - 1][j - 1] ^= 1;
            }
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (b[i][m] == 1 && b[i][j] == 1 && b[n][j] == 1)
            {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 1; i < n; ++i)
    {
        memset(c, false, sizeof c);
        dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans += b[i][j];

    int q = 0;
    for (int i = 1; i < m; ++i)
    {
        if (u[i])
            ++q;
    }

    if (b[n][m] == 1)
    {
        if (q)
        {
            --q;
            ans -= 2;
        }
    }

    ans -= q / 2 * 2;

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
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}