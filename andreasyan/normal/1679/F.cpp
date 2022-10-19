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
const int N = 50004, M = 998244353;

int n, m;
int g[10];

int s[(1 << 10)];
int dp[(1 << 10)];

void ph(int& x, int y)
{
    x = (x + y) % M;
}

vector<int> v[(1 << 10)];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < 10; ++i)
    {
        g[i] = (((1 << 10) - 1) ^ (1 << i));
    }
    for (int ii = 0; ii < m; ++ii)
    {
        int i, j;
        cin >> i >> j;
        g[i] ^= (1 << j);
        g[j] ^= (1 << i);
    }

    for (int x = 0; x < (1 << 10); ++x)
    {
        for (int i = 0; i < 10; ++i)
        {
            if ((x & (1 << i)))
                v[x].push_back(i);
        }
    }

    s[(1 << 10) - 1] = 1;
    for (int ii = 1; ii <= n; ++ii)
    {
        memset(dp, 0, sizeof dp);
        for (int x = 0; x < (1 << 10); ++x)
        {
            for (int i = 0; i < sz(v[x]); ++i)
            {
                ph(dp[(x & (((1 << 10) - 1) ^ ((1 << (v[x][i] + 1)) - 1))) | g[v[x][i]]], s[x]);
            }
        }
        for (int x = 0; x < (1 << 10); ++x)
            ph(s[x], dp[x]);
    }

    int ans = 0;
    for (int x = 0; x < (1 << 10); ++x)
        ans = (ans + dp[x]) % M;
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