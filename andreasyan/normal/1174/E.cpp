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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];

void por()
{
    int uans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int yans = 0;
        int x = i;
        for (int j = 2; j <= n; ++j)
        {
            while (x % j == 0)
            {
                ++yans;
                x /= j;
            }
        }
        uans = max(uans, yans + 1);
    }
    printf("%d\n", uans);

    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }
    int ans = 0;
    do
    {
        bool c[30] = {};
        int g = 0;
        for (int i = 0; i < n; ++i)
        {
            g = gcd(g, a[i]);
            c[g] = true;
        }
        int yans = 0;
        for (int i = 0; i < 30; ++i)
        {
            if (c[i])
                ++yans;
        }
        if (yans == uans)
            ++ans;
    } while (next_permutation(a, a + n));
    printf("%d\n", ans);
}

int f[N];
int rf[N];

int C(int n, int k)
{
    return ((f[n] * 1LL * rf[k]) % M * rf[n - k]) % M;
}

int u[N];

vector<int> dp[N];

void solv()
{
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;

    rf[n] = ast(f[n], M - 2);
    for (int i = n - 1; i >= 0; --i)
        rf[i] = (rf[i + 1] * 1LL * (i + 1)) % M;

    for (int i = 2; i <= n; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j <= n; j += i)
        {
            if (!u[j])
            {
                u[j] = i;
            }
        }
    }

    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = i;
        vector<int> v;
        while (x > 1)
        {
            v.push_back(u[x]);
            x /= u[x];
        }
        maxu = max(maxu, sz(v));

        if (!v.empty() && v.back() > 3 || (v.size() >= 2 && v.back() == 3 && v[v.size() - 2] == 3))
            continue;

        dp[i].assign(n / i + 1, 0);

        for (int k = (n / i); k >= 0; --k)
        {
            if (i == 1)
            {
                dp[i][k] = f[(n / i) - k];
                continue;
            }
            if (k + 1 <= (n / i))
                dp[i][k] = (dp[i][k] + dp[i][k + 1] * 1LL * ((n / i) - k)) % M;
            for (int j = 0; j < v.size(); ++j)
            {
                if (!j || v[j] != v[j - 1])
                {
                    dp[i][k] = (dp[i][k] + dp[i / v[j]][k + 1] * 1LL * ((n / (i / v[j])) - (n / i))) % M;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = i;
        vector<int> v;
        while (x > 1)
        {
            v.push_back(u[x]);
            x /= u[x];
        }
        if (sz(v) == maxu)
            ans = (ans + dp[i][1]) % M;
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    scanf("%d", &n);
    //por();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}