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
const int N = 7, M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n;
int p[N][N];

int sh[N][(1 << N)];

vector<int> v[N];
int rv[(1 << 20)];

int u[(1 << N)][(1 << N)];

int dp[(1 << 20)], ndp[(1 << 20)];

int b[(1 << 20)];
int uu[(1 << 20)];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> p[i][j];
            p[i][j] = (p[i][j] * 1LL * ast(100, M - 2)) % M;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int x = 0; x < (1 << n); ++x)
        {
            sh[i][x] = 1;
            for (int j = 0; j < n; ++j)
            {
                if ((x & (1 << j)))
                    sh[i][x] = (sh[i][x] * 1LL * p[i][j]) % M;
                else
                    sh[i][x] = (sh[i][x] * 1LL * (1 - p[i][j])) % M;
            }
            sh[i][x] = (sh[i][x] + M) % M;
        }
    }

    for (int x = 0; x < (1 << n); ++x)
    {
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q;
        }
        v[q].push_back(x);
    }

    for (int x = 0; x < (1 << n); ++x)
    {
        int q = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q;
        }
        for (int y = 0; y < (1 << n); ++y)
        {
            for (int i = 0; i < n; ++i)
            {
                if ((y & (1 << i)))
                {
                    if (!(x & (1 << i)))
                    {
                        int z = (x | (1 << i));
                        u[x][y] |= (1 << (lower_bound(all(v[q + 1]), z) - v[q + 1].begin()));
                    }
                }
            }
        }
    }

    for (int x = 0; x < (1 << 20); ++x)
    {
        for (int i = 0; i < 20; ++i)
        {
            if ((x & (1 << i)))
            {
                b[x] = i;
                break;
            }
        }
    }

    dp[1] = 1;
    for (int q = 0; q < n; ++q)
    {
        memset(ndp, 0, sizeof ndp);
        for (int y = 0; y < (1 << n); ++y)
        {
            for (int xx = 0; xx < (1 << sz(v[q])); ++xx)
            {
                if (xx)
                    uu[xx] = (uu[(xx ^ (1 << b[xx]))] | u[v[q][b[xx]]][y]);

                /*uu[xx] = 0;
                for (int i = 0; i < sz(v[q]); ++i)
                {
                    if ((xx & (1 << i)))
                        uu[xx] |= u[v[q][i]][y];
                }*/

                ndp[uu[xx]] = (ndp[uu[xx]] + dp[xx] * 1LL * sh[q][y]) % M;
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }

    cout << dp[1] << "\n";
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