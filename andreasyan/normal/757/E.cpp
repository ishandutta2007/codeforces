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
const int N = 1000006, M = 1000000007;

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

int p[N];

int f[N * 2], rf[N * 2];
int ast2[N];

void pre()
{
    for (int i = 2; i < N; ++i)
    {
        if (p[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (!p[j])
                p[j] = i;
        }
    }

    f[0] = 1;
    for (int i = 1; i < N * 2; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N * 2 - 1] = ast(f[N * 2 - 1], M - 2);
    for (int i = N * 2 - 2; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
    ast2[0] = 1;
    for (int i = 1; i < N; ++i)
        ast2[i] = (ast2[i - 1] * 2) % M;
}

int C(int n, int k)
{
    if (k == -1)
        return 1;
    return ((f[n] * 1LL * rf[k]) % M * rf[n - k]) % M;
}

int dp[8][8];
void solv()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int r, n;
        scanf("%d%d", &r, &n);
        vector<pair<int, int> > v;
        while (n > 1)
        {
            if (v.empty() || v.back().fi != p[n])
                v.push_back(m_p(p[n], 1));
            else
                v.back().se++;
            n /= p[n];
        }
        if (r == 0)
        {
            printf("%d\n", ast2[sz(v)]);
            continue;
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < sz(v); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 1LL * C(v[i].se + 1 + r - 2, r - 1)) % M;
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * 1LL * C(v[i].se + r - 1, r)) % M;
            }
        }
        int ans = 0;
        for (int j = 0; j <= sz(v); ++j)
            ans = (ans + dp[sz(v)][j] * 1LL * ast2[j]) % M;
        printf("%d\n", ans);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}