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
const int N = 1000006;
const int M = 998244353;

int ast(int x, ll n)
{
    n %= (M - 1);
    if (n < 0)
        n += (M - 1);
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
    if (n < k)
        return 0;
    return (f[n] * 1LL * rf[k] % M * rf[n - k]) % M;
}

int n;

void solv()
{
    cin >> n;

    int ans = ast((ast(3, n) - 3 + M) % M, n);
    for (int i = 1; i <= n; ++i)
    {
        int yans1 = (ast(3, i) - 3 + M) % M;
        yans1 = (yans1 * 1LL * ast(3, n * 1LL * n - i * n)) % M;
        int yans2 = ast((ast(3, n - i) - 1 + M) % M, n);
        yans2 = (yans2 * 3LL) % M;
        int yans = (yans1 + yans2) % M;
        yans = (yans * 1LL * C(n, i)) % M;
        if (i % 2 == 0)
            ans = (ans + yans) % M;
        else
            ans = (ans - yans + M) % M;
    }

    ans = (ast(3, n * 1LL * n) - ans + M) % M;
    cout << ans << "\n";
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