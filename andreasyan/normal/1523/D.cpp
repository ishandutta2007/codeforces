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
const int N = 200005, M = 66, P = 17;

int n, m, p;
char a[N][M];

int t[N];

int dp[(1 << P)][P];

int ans;
char ansc[M];
void solv()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int j = 0; j < m; ++j)
        ansc[j] = '0';
    for (int ii = 0; ii < 60; ++ii)
    {
        int u = rnd() % n + 1;
        vector<int> v;
        for (int j = 0; j < m; ++j)
        {
            if (a[u][j] == '1')
                v.push_back(j);
        }
        for (int i = 1; i <= n; ++i)
        {
            t[i] = 0;
            for (int j = 0; j < sz(v); ++j)
            {
                if (a[i][v[j]] == '1')
                    t[i] |= (1 << j);
            }
        }

        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i)
            dp[t[i]][0]++;

        for (int j = 1; j <= sz(v); ++j)
        {
            for (int x = (1 << sz(v)) - 1; x >= 0; --x)
            {
                if ((x & (1 << (j - 1))))
                    dp[x][j] = dp[x][j - 1];
                else
                    dp[x][j] = (dp[x][j - 1] + dp[(x ^ (1 << (j - 1)))][j - 1]);
            }
        }

        for (int x = 0; x < (1 << sz(v)); ++x)
        {
            int q = 0;
            for (int j = 0; j < sz(v); ++j)
            {
                if ((x & (1 << j)))
                    ++q;
            }

            if (dp[x][sz(v)] >= (n / 2 + n % 2))
            {
                if (q > ans)
                {
                    ans = q;
                    for (int j = 0; j < m; ++j)
                        ansc[j] = '0';
                    for (int j = 0; j < sz(v); ++j)
                    {
                        if ((x & (1 << j)))
                            ansc[v[j]] = '1';
                    }
                }
            }
        }
    }

    cout << ansc << "\n";
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