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
const int N = 2000006, M = 1000000007;

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
    return f[n] * 1LL * rf[k] % M * rf[n - k] % M;
}

int n;

void solv()
{
    cin >> n;

    int ans = 0;
    for (int q = n; q >= 0; --q)
    {
        if (q % 2 == 1)
            continue;
        if (q < n - q)
            continue;
        int yans;
        if (q == n)
            yans = 1;
        else
        {
            yans = (n * 1LL * C(n - 2 - (n - q - 1), n - q - 1)) % M;
            yans = (yans * 1LL * ast(n - q, M - 2)) % M;
        }
        yans = (yans * 2LL) % M;
        yans = (yans * 1LL * f[q]) % M;
        ans = (ans + yans) % M;
    }

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