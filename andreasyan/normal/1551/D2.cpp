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
const int N = 102;
const int xx[4] = {0, 1, 0, -1};
const int yy[4] = {1, 0, -1, 0};

bool dp[N][N][N * N];
void pre()
{
    for (int i = 0; i < N; ++i)
        dp[i][0][0] = dp[0][i][0] = true;
    for (int n = 1; n < N; ++n)
    {
        for (int m = 1; m < N; ++m)
        {
            for (int k = 0; k <= n * m / 2; ++k)
            {
                int kk = n * m / 2 - k;

                if (m % 2 == 0 && k >= m / 2)
                    dp[n][m][k] |= dp[n - 1][m][k - m / 2];
                if (n % 2 == 0 && kk >= n / 2)
                    dp[n][m][k] |= dp[n][m - 1][k];
                if (n % 2 + m % 2 == 1 && k >= m / 2 && kk >= n / 2)
                    dp[n][m][k] |= dp[n - 1][m - 1][k - m / 2];
            }
        }
    }
}

int n, m, k;

char a[N][N];

void solv()
{
    cin >> n >> m >> k;

    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            a[i][j] = 0;
        }
    }

    if (dp[n][m][k])
    {
        cout << "YES\n";
        vector<pair<pair<int, int>, pair<int, int> > > v;
        int cn = n, cm = m;
        while (1)
        {
            if (n == 0 || m == 0)
                break;
            int kk = n * m / 2 - k;

            int nn, nm, nk;

            if (m % 2 == 0 && k >= m / 2)
            {
                if (dp[n - 1][m][k - m / 2])
                {
                    int i = n;
                    for (int j = 1; j < m; j += 2)
                    {
                        v.push_back(m_p(m_p(i, j), m_p(i, j + 1)));
                    }
                    nn = n - 1;
                    nm = m;
                    nk = k - m / 2;
                }
            }
            if (n % 2 == 0 && kk >= n / 2)
            {
                if (dp[n][m - 1][k])
                {
                    int j = m;
                    for (int i = 1; i < n; i += 2)
                    {
                         v.push_back(m_p(m_p(i, j), m_p(i + 1, j)));
                    }
                    nn = n;
                    nm = m - 1;
                    nk = k;
                }
            }
            if (n % 2 + m % 2 == 1 && k >= m / 2 && kk >= n / 2)
            {
                if (dp[n - 1][m - 1][k - m / 2])
                {
                    int i = n;
                    for (int j = 1; j < m; j += 2)
                    {
                        v.push_back(m_p(m_p(i, j), m_p(i, j + 1)));
                    }
                    int j = m;
                    for (int i = 1; i < n; i += 2)
                    {
                        v.push_back(m_p(m_p(i, j), m_p(i + 1, j)));
                    }
                    nn = n - 1;
                    nm = m - 1;
                    nk = k - m / 2;
                }
            }
            n = nn;
            m = nm;
            k = nk;
        }

        n = cn;
        m = cm;

        for (int i = 0; i < sz(v); ++i)
        {
            bool c[26] = {};
            for (int j = 0; j < 4; ++j)
            {
                {
                    int hx = v[i].fi.fi + xx[j];
                    int hy = v[i].fi.se + yy[j];
                    if (a[hx][hy])
                        c[a[hx][hy] - 'a'] = true;
                }
                {
                    int hx = v[i].se.fi + xx[j];
                    int hy = v[i].se.se + yy[j];
                    if (a[hx][hy])
                        c[a[hx][hy] - 'a'] = true;
                }
            }
            for (int j = 0; j < 26; ++j)
            {
                if (!c[j])
                {
                    a[v[i].fi.fi][v[i].fi.se] = j + 'a';
                    a[v[i].se.fi][v[i].se.se] = j + 'a';
                    break;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    else
        cout << "NO\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}