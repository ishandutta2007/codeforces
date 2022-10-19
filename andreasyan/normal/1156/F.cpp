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
const int N = 5003, M = 998244353;

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

void pre()
{
    for (int i = 0; i < N; ++i)
        r[i] = ast(i, M - 2);
}

int n;
int a[N];
int p[N];

int dp[N][N];
int s[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int q = n; q >= 0; --q)
    {
        for (int x = n; x >= 1; --x)
        {
            if (q > p[x - 1])
                continue;
            if (a[x] == 0)
                continue;
            /*for (int y = x + 1; y <= n; ++y)
            {
                dp[x][q] = (dp[x][q] + (dp[y][q + 1] * 1LL * r[n - q - 1]) % M * a[y]) % M;
            }*/
            dp[x][q] = (s[q + 1][x + 1] * 1LL * r[n - q - 1]) % M;
            dp[x][q] = (dp[x][q] + (a[x] - 1) * 1LL * r[n - q - 1]) % M;
        }
        for (int y = n; y >= 1; --y)
        {
            s[q][y] = (s[q][y + 1] + dp[y][q] * 1LL * a[y]) % M;
        }
    }
    int ans = 0;
    for (int x = 1; x <= n; ++x)
        ans = (ans + ((dp[x][0] * 1LL * r[n]) % M * a[x])) % M;
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}