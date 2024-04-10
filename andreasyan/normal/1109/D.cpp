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
const int N = 2000006;
const int M = 1000000007;
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
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;
}

int C(int n, int k)
{
    return (((f[n] * 1LL * rf[k]) % M) * 1LL * rf[n - k]) % M;
}

int F(int n, int k)
{
    if (n == k)
        return 1;
    return (k * 1LL * ast(n, n - k - 1)) % M;
}

int n, m;

bool solv()
{
    int aaa;
    scanf("%d%d%d%d", &n, &m, &aaa, &aaa);
    int ans = 0;
    for (int i = 0; i <= n - 2 && i + 1 <= m; ++i)
    {
        int yans = 1;
        yans = (yans * 1LL * (C(n - 2, i) * 1LL * f[i]) % M) % M;
        yans = (yans * 1LL * C(m - (i + 1) + i, i)) % M;
        yans = (yans * 1LL * ast(m, n - 1 - (i + 1))) % M;
        yans = (yans * 1LL * F(n, i + 2)) % M;
        ans = (ans + yans) % M;
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
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}