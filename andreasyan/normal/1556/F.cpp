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
const int N = 16, K = 5000006, M = 1000000007;

int ast0(int x, int n)
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
int a[N];

int h[N][N];
int q[(1 << N)];

int ast[N];
int sast[(1 << N)];

int sh0[N][(1 << N)];
int sh[K];

int dp[(1 << N)];

void ph(int& x, int y)
{
    x = (x + y) % M;
}

vector<int> g[N];

bool c[N];
void dfs(int x)
{
    if (c[x])
        return;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
    }
}

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            h[i][j] = (a[i] * 1LL * ast0(a[i] + a[j], M - 2)) % M;
        }
    }

    /*int fans0[(1 << N)] = {};
    {
        int ans = 0;
        for (int x = 0; x < (1 << (n * (n - 1)) / 2); ++x)
        {
            for (int i = 0; i < n; ++i)
                g[i].clear();
            int k = 0;
            int sh = 1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if ((x & (1 << k)))
                    {
                        g[i].push_back(j);
                        sh = (sh * 1LL * h[i][j]) % M;
                    }
                    else
                    {
                        g[j].push_back(i);
                        sh = (sh * 1LL * h[j][i]) % M;
                    }
                    ++k;
                }
            }
            int q = 0;
            for (int i = 0; i < n; ++i)
            {
                memset(c, false, sizeof c);
                dfs(i);
                bool z = true;
                for (int i = 0; i < n; ++i)
                {
                    if (!c[i])
                    {
                        z = false;
                        break;
                    }
                }
                q += z;

                {
                    int x = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        if (c[i])
                            x |= (1 << i);
                    }
                    fans0[x] = (fans0[x] + sh) % M;
                }
            }
            ans = (ans + sh * 1LL * q) % M;
        }
        cout << ans << "\n";
    }*/

    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q[x];
        }
    }

    ast[0] = 1;
    for (int i = 1; i < n; ++i)
        ast[i] = (ast[i - 1] * 3);
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                sast[x] += ast[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int x = 0; x < (1 << n); ++x)
        {
            sh0[i][x] = 1;
            for (int j = 0; j < n; ++j)
            {
                if ((x & (1 << j)))
                    sh0[i][x] = (sh0[i][x] * 1LL * h[i][j]) % M;
            }
        }
    }
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int y = x; y; y = ((y - 1) & x))
        {
            sh[sast[x] + sast[y]] = 1;
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)) && !(y & (1 << i)))
                    sh[sast[x] + sast[y]] = (sh[sast[x] + sast[y]] * 1LL * sh0[i][y]) % M;
            }
        }
    }

    int ans = 0;
    for (int s = 0; s < n; ++s)
    {
        memset(dp, 0, sizeof dp);
        for (int x = 0; x < (1 << n); ++x)
        {
            if (!(x & (1 << s)))
                continue;

            dp[x] = 1;
            for (int y = x; y; y = ((y - 1) & x))
            {
                if (y == x)
                    continue;
                if (!(y & (1 << s)))
                    continue;
                dp[x] = (dp[x] - dp[y] * 1LL * sh[sast[x] + sast[y]]) % M;
            }
        }
        ans = (ans + dp[(1 << n) - 1]) % M;
    }
    ans = (ans + M) % M;

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