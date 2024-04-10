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
const int N = 1003, l = 10;

int n, m;
int a[N][N];
short u[N][N];

short t[N][N][l][l];
int g[N];
short qry(int x1, int x2, int y1_, int y2)
{
    int xx = g[x2 - x1 + 1];
    int yy = g[y2 - y1_ + 1];

    return max(max(t[x2][y2][xx][yy], t[x1 + (1 << xx) - 1][y1_ + (1 << yy) - 1][xx][yy]),
               max(t[x1 + (1 << xx) - 1][y2][xx][yy], t[x2][y1_ + (1 << yy) - 1][xx][yy]));
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!a[i][j])
                u[i][j] = 0;
            else
            {
                if (u[i - 1][j] != u[i][j - 1])
                    u[i][j] = min(u[i - 1][j], u[i][j - 1]) + 1;
                else
                {
                    if (a[i - u[i - 1][j]][j - u[i - 1][j]])
                        u[i][j] = u[i - 1][j] + 1;
                    else
                        u[i][j] = u[i - 1][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            t[i][j][0][0] = u[i][j];

            for (int ki = 1; i - (1 << ki) + 1 >= 1; ++ki)
            {
                t[i][j][ki][0] = max(t[i][j][ki - 1][0], t[i - (1 << (ki - 1))][j][ki - 1][0]);
            }
            for (int kj = 1; j - (1 << kj) + 1 >= 1; ++kj)
            {
                t[i][j][0][kj] = max(t[i][j][0][kj - 1], t[i][j - (1 << (kj - 1))][0][kj - 1]);
            }

            for (int ki = 1; i - (1 << ki) + 1 >= 1; ++ki)
            {
                for (int kj = 1; j - (1 << kj) + 1 >= 1; ++kj)
                {
                    int ii = i - (1 << (ki - 1));
                    int jj = j - (1 << (kj - 1));
                    t[i][j][ki][kj] = max(max(t[i][j][ki - 1][kj - 1], t[ii][jj][ki - 1][kj - 1]),
                                          max(t[ii][j][ki - 1][kj - 1], t[i][jj][ki - 1][kj - 1]));
                }
            }
        }
    }
    for (int i = 1; i <= max(n, m); ++i)
    {
        while ((1 << (g[i] + 1)) <= i)
            ++g[i];
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int x1, y1_, x2, y2;
        cin >> x1 >> y1_ >> x2 >> y2;

        int ans = 0;
        int l = 1, r = min(x2 - x1 + 1, y2 - y1_ + 1);
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry(x1 + m - 1, x2, y1_ + m - 1, y2) >= m)
            {
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        cout << ans << "\n";
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