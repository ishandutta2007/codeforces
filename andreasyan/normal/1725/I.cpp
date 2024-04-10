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
const int N = 200005;
const int M = 998244353;

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
    if (k < 0 || k > n)
        return 0;
    return (f[n] * 1LL * rf[k]) % M * rf[n - k] % M;
}

ll n;

int p[N];
int q[N];
int ans[N];

int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

int dp[N];
void solv()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        q[i] = 1;
        ans[i] = 1;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;

        x = fi(x);
        y = fi(y);

        int yans = (q[x] * 1LL * q[y]) % M;
        yans = (yans * 1LL * yans) % M;
        yans = (yans * 1LL * ans[x]) % M;
        yans = (yans * 1LL * ans[y]) % M;

        ans[y] = yans;
        q[y] += q[x];
        p[x] = y;
    }

    int yans = ans[fi(1)];
    /*yans = (yans * 1LL * C(2 * (n - 2), (n - 2))) % M;
    yans = (yans * 1LL * ast(n - 1, M - 2)) % M;
    n = (n * 2 - 2);
    n = (n * (n - 1)) / 2;
    n %= M;
    yans = (yans * n) % M;*/
    for (int i = 1; i < n; ++i)
    {
        yans = (yans * 1LL * (2 * i - 1)) % M;
    }

    cout << yans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}