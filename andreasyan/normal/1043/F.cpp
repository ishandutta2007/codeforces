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
const int N = 300005, M = 912343247;

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

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

int f[N], rf[N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    rf[N - 1] = ast(f[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
    {
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
    }
}

int C(int n, int k)
{
    if (k > n)
        return 0;
    return (((f[n] * 1LL * rf[k]) % M) * rf[n - k]) % M;
}

bool c[N];

int dp[N][8];

void solv()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x;
        scanf("%d", &x);
        c[x] = true;
    }
    for (int i = N - 1; i >= 1; --i)
    {
        int q = 0;
        for (int j = i; j < N; j += i)
        {
            if (c[j])
                ++q;
        }
        for (int k = 1; k <= 7; ++k)
            dp[i][k] = C(q, k);
        for (int j = i + i; j < N; j += i)
        {
            for (int k = 1; k <= 7; ++k)
            {
                dp[i][k] = (dp[i][k] - dp[j][k]) % M;
            }
        }
    }
    for (int k = 1; k <= 7; ++k)
    {
        if (dp[1][k])
        {
            printf("%d\n", k);
            return;
        }
    }
    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    /*int x = 912343234;
    while (!prime(x))
        ++x;
    printf("%d\n", x);*/
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}