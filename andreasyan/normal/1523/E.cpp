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
const int N = 500005;
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
    if (k < 0 || k > n)
        return 0;
    return (f[n] * 1LL * rf[k]) % M * rf[n - k] % M;
}

int T(int n, int k, int j)
{
    if (n - (k - 1) * 1LL * (j - 1) < 0)
        return 0;
    return C(n - (k - 1) * (j - 1), j);
}

int TT(int n, int k, int j)
{
    return (T(n, k, j) * 1LL * f[j]) % M;
}

int n, k;

void solv()
{
    /*cin >> n;
    for (int k = 2; k <= n; ++k)
    {
        int ans[40] = {};
        bool z[100000] = {};
        for (int x = 0; x < (1 << n); ++x)
        {
            z[x] = true;
            int u = -n * 2;
            int q = 0;
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                {
                    if ((i - u + 1) <= k)
                    {
                        z[x] = false;
                        break;
                    }
                    u = i;
                    ++q;
                }
            }
            ans[q] += z[x];
        }
        int anss[40] = {};
        for (int x = 0; x < (1 << n); ++x)
        {
            if (!z[x])
                continue;
            int q = 0;
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                    ++q;
            }
            for (int i = 0; i < n; ++i)
            {
                if (!(x & (1 << i)))
                {
                    if (!z[x + (1 << i)])
                        anss[q + 1] += f[q];
                }
            }
        }
        for (int q = 1; q <= n; ++q)
        {
            int u = (TT(n, k, q - 1) * 1LL * (n - q + 1)) % M;
            u = (u - TT(n, k, q) + M) % M;
            assert(u == anss[q]);
        }
        for (int q = 0; q <= n; ++q)
        {
            assert(ans[q] == T(n, k, q));
            cout << ans[q] << ' ';
        }
        cout << "\n";
        for (int j = 0; j <= n; ++j)
        {
            cout << T(n, k, j) << ' ';
        }
        cout << "\n";
    }
    return;*/

    cin >> n >> k;

    /*int yans = 0;
    for (int q = 1; q <= n; ++q)
    {
        int u = (TT(n, k, q - 1) * 1LL * (n - q + 1)) % M;
        u = (u - TT(n, k, q) + M) % M;
        yans = (yans + u) % M;
    }
    yans = ast(yans, M - 2);*/

    int ans = 0;
    for (int q = 1; q <= n; ++q)
    {
        int u = (TT(n, k, q - 1) * 1LL * (n - q + 1)) % M;
        u = (u - TT(n, k, q) + M) % M;
        u = (u * 1LL * f[n - q]) % M;
        u = (u * 1LL * rf[n]) % M;
        u = (u * 1LL * q) % M;
        ans = (ans + u) % M;
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
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}