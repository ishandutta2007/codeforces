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
const int N = 102, M = 15;

int n;
char ans[N][M][M][M];
bool c[N][N];

void solv()
{
    cin >> n;

    if (n == 2)
    {
        cout << "-1\n";
        return;
    }

    c[0][0] = true;
    for (int m = 1; m <= 12; ++m)
    {
        for (int nn = 0; nn <= n; ++nn)
        {
            if (m * 2 - 1 > nn)
                continue;
            int q = nn - (m * 2 - 1);
            for (int mm = 0; mm < m; ++mm)
            {
                if (c[q][mm])
                {
                    c[nn][m] = true;
                    for (int i = 1; i <= m; ++i)
                    {
                        for (int j = 1; j <= m; ++j)
                        {
                            ans[nn][m][i][j] = '.';
                        }
                    }
                    for (int i = 1; i <= m; ++i)
                        ans[nn][m][i][1] = 'o';
                    for (int j = 1; j <= m; ++j)
                        ans[nn][m][m][j] = 'o';
                    for (int i = 1; i <= mm; ++i)
                    {
                        for (int j = 1; j <= mm; ++j)
                        {
                            ans[nn][m][m - mm - 1 + i][j + 1] = ans[q][mm][i][j];
                        }
                    }
                }
            }
        }
    }

    for (int m = 1; m <= 12; ++m)
    {
        if (c[n][m])
        {
            cout << m << "\n";
            for (int i = 1; i <= m; ++i)
            {
                for (int j = 1; j <= m; ++j)
                {
                    cout << ans[n][m][i][j];
                }
                cout << "\n";
            }
            return;
        }
    }
    cout << "-1\n";
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