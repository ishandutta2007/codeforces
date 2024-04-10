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
const int N = 100005;
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

int n;
int a[N];

ll p[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1 && p[i] == p[i - 1])
            continue;
        int ir;
        for (int k = i; k <= n; ++k)
        {
            if (p[k] != p[i])
                break;
            ir = k;
        }

        int l = ir + 1, r = n + 1;
        int j = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[n] - p[m - 1] >= p[i])
            {
                j = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        if (j == -1)
            continue;
        if (p[n] - p[j - 1] != p[i])
            continue;

        if (j == ir + 1)
        {
            int qq = ir - i + 2;
            if (j == n + 1)
                --qq;
            int yans = 0;
            for (int q = 0; q <= qq; q += 2)
            {
                yans = (yans + C(qq, q)) % M;
            }
            ans = (ans * 1LL * yans) % M;
        }
        else
        {
            if (j == n + 1)
            {
                if (a[n])
                    continue;
                --j;
            }
            int jl;
            for (int k = j; k >= 1; --k)
            {
                if (p[n] - p[k - 1] != p[n] - p[j - 1])
                    break;
                jl = k;
            }

            int yans = 0;
            for (int q = 0; q <= min(ir - i + 1, j - jl + 1); ++q)
            {
                yans = (yans + C(ir - i + 1, q) * 1LL * C(j - jl + 1, q)) % M;
            }
            ans = (ans * 1LL * yans) % M;
        }
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
    {
        solv();
    }
    return 0;
}