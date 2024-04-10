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
const int N = 203;

int n, m;
char a[N][N];

vector<int> g[N * N];

int u[N * N];
bool c[N * N];
vector<int> v;
bool dfs(int x)
{
    if (c[x])
        return false;
    c[x] = true;
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (!u[h])
        {
            u[h] = x;
            return true;
        }
        if (dfs(u[h]))
        {
            u[h] = x;
            return true;
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
            if (a[i][j] == '.')
                continue;

            vector<int> v1;
            if (a[i][j + 1] == '#')
                v1.push_back((i - 1) * m + j);
            if (a[i][j - 1] == '#')
                v1.push_back((i - 1) * m + (j - 1));

            vector<int> v2;
            if (a[i + 1][j] == '#')
                v2.push_back((i - 1) * m + j);
            if (a[i - 1][j] == '#')
                v2.push_back((i - 2) * m + j);

            for (int i = 0; i < sz(v1); ++i)
            {
                for (int j = 0; j < sz(v2); ++j)
                {
                    g[v1[i]].push_back(v2[j]);
                }
            }
        }
    }

    int q = 0;
    for (int i = 1; i <= n * m; ++i)
    {
        q -= dfs(i);
        while (!v.empty())
        {
            c[v.back()] = false;
            v.pop_back();
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '#' && a[i][j + 1] == '#')
                ++q;
            if (a[i][j] == '#' && a[i + 1][j] == '#')
                ++q;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '#')
                ++ans;
        }
    }
    ans -= q;

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
    {
        solv();
    }
    return 0;
}