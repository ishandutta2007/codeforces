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
const int N = 5003, M = 1000000007;

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
char a[N];

int dp[N][27];
int s[N];

int ndp[N];

int f[N * 2];

int C(int n, int k)
{
    return (((f[n] * 1LL * ast(f[k], M - 2)) % M) * 1LL * ast(f[n - k], M - 2)) % M;
}

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    dp[0][26] = 1;
    s[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        memset(ndp, 0, sizeof ndp);
        for (int j = 0; j < n; ++j)
        {
            ndp[j + 1] = (ndp[j + 1] + (s[j] - dp[j][a[i] - 'a'] + M) % M) % M;
        }
        for (int j = 1; j <= n; ++j)
        {
            s[j] = (s[j] - dp[j][a[i] - 'a'] + M) % M;
            dp[j][a[i] - 'a'] = ndp[j];
            s[j] = (s[j] + dp[j][a[i] - 'a']) % M;
        }
    }
    f[0] = 1;
    for (int i = 1; i <= n * 2; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    int ans = 0;
    for (int j = 1; j <= n; ++j)
    {
        ans = (ans + s[j] * 1LL * C(n - 1, j - 1)) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}