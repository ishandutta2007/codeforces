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

int n;
int a[N];

int p[N];
void solv()
{
    cin >> n;
    for (int i = 0; i <= n; ++i)
        cin >> a[i];

    /*int ans = 0;
    p[0] = 1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < a[i]; ++j)
        {
            if (j)
                p[j] += p[j - 1];
            ans += p[j];
        }
    }
    cout << ans << "\n";

    int ans1 = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < a[i]; ++j)
        {
            ans1 += C(i + j, i);
        }
    }
    cout << ans1 << "\n";*/

    int ans2 = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans2 = (ans2 + C(i + a[i], i + 1)) % M;
    }
    cout << ans2 << "\n";
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