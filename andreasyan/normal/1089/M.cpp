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
const int N = 12, M = 102;

int n;
int a[N][N];

int c[N];

vector<int> v;
void dfs0(int x)
{
    c[x] = 1;
    for (int h = 1; h <= n; ++h)
    {
        if (!a[x][h])
            continue;
        if (!c[h])
            dfs0(h);
    }
    v.push_back(x);
}

int k;
void dfs1(int x)
{
    c[x] = k;
    for (int h = 1; h <= n; ++h)
    {
        if (!a[h][x])
            continue;
        if (!c[h])
            dfs1(h);
    }
}

vector<int> gg[N];

bool cc[N];
void dfs2(int x)
{
    cc[x] = true;
    for (int i = 0; i < gg[x].size(); ++i)
    {
        int h = gg[x][i];
        if (!cc[h])
            dfs2(h);
    }
    v.push_back(x);
}

char ans[M][M][M];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
            dfs0(x);
    }
    reverse(all(v));

    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = v[i];
        if (!c[x])
        {
            ++k;
            dfs1(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            if (a[x][y] && c[x] != c[y])
                gg[c[x]].push_back(c[y]);
        }
    }

    v.clear();
    for (int i = 1; i <= k; ++i)
    {
        if (!cc[i])
            dfs2(i);
    }

    int k0 = (k + 1) * 5 + 10;
    int n0 = n * 3;
    int m0 = (k + 1) * 5 + 10;

    for (int i = k0; i >= 1; --i)
    {
        for (int j = 1; j <= n0; ++j)
        {
            for (int k = 1; k <= m0; ++k)
            {
                ans[i][j][k] = '.';
            }
        }
    }

    for (int i = 0; i < k; ++i)
    {
        int h = 2 + i * 5;
        int s = i * 4 + 1;

        for (int u = 1; u <= n0; ++u)
        {
            ans[h][u][s + 1] = '#';

            for (int hh = h + 1; hh <= k0; ++hh)
            {
                ans[hh][u][s] = ans[hh][u][s + 2] = '#';
            }
        }

        for (int u = 1; u <= m0; ++u)
        {
            ans[h][2 + i * 3][u] = '#';
        }
        ans[h + 1][2 + i * 3][s] = ans[h + 1][2 + i * 3][s + 2] = '.';

        for (int x = 1; x <= n; ++x)
        {
            if (c[x] == v[i])
                ans[h + 1][x][s + 1] = x + '0';
        }
    }

    for (int i = 0; i < k; ++i)
    {
        int h = 2 + i * 5;
        int s = i * 4 + 1;
        for (int jj = 0; jj < gg[v[i]].size(); ++jj)
        {
            int j;
            for (int u = 0; u < k; ++u)
            {
                if (v[u] == gg[v[i]][jj])
                {
                    j = u;
                    break;
                }
            }

            assert(j < i);

            ans[h + 1][2 + j * 3][s] = ans[h + 1][2 + j * 3][s + 2] = '.';
        }
    }

    cout << m0 << ' ' << n0 << ' ' << k0 << "\n";
    for (int i = k0; i >= 1; --i)
    {
        for (int j = 1; j <= n0; ++j)
        {
            for (int k = 1; k <= m0; ++k)
            {
                cout << ans[i][j][k];
            }
            cout << "\n";
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