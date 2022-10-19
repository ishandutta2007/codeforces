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
const int N = 410, M = 1000000007;

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

int r[N];
int c[N][N];
int C(int n, int k)
{
    if (n < N)
        return c[n][k];
    int ans = 1;
    for (int i = n; i > n - k; --i)
        ans = (ans * 1LL * i) % M;
    for (int i = 1; i <= k; ++i)
        ans = (ans * 1LL * r[i]) % M;
    return ans;
}

int n, k;

int dp[N][N];

void solv()
{
    cin >> n >> k;

    /*set<vector<int> > s[8];

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    s[0].insert(v);

    for (int i = 1; i < 8; ++i)
    {
        for (auto it = s[i - 1].begin(); it != s[i - 1].end(); ++it)
        {
            vector<int> v = *it;
            for (int j = 0; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    swap(v[j], v[k]);
                    s[i].insert(v);
                    swap(v[j], v[k]);
                }
            }
        }
        cout << sz(s[i]) << "\n";
    }*/

    for (int i = 1; i < N; ++i)
        r[i] = ast(i, M - 2);
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
    }

    for (int j = 0; j < N; j += 2)
        dp[0][j] = dp[1][j] = 1;
    for (int j = 0; j < N; ++j)
        dp[2][j] = 1;
    for (int i = 3; i < N; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j < N; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * 1LL * (i - 1)) % M;
    }

    for (int g = 1; g <= k; ++g)
    {
        int ans = 0;
        for (int q = 0; q <= min(2 * g, n); ++q)
        {
            int u = 0;
            for (int j = q; j >= 0; --j)
            {
                if ((q - j) % 2 == 0)
                    u = (u + dp[j][g] * 1LL * C(q, q - j)) % M;
                else
                    u = (u - (dp[j][g] * 1LL * C(q, q - j)) % M + M) % M;
            }
            ans = (ans + C(n, q) * 1LL * u) % M;
        }
        cout << ans << ' ';
    }
    cout << "\n";
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