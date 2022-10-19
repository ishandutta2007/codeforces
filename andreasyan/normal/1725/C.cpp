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
const int N = 300005, M = 998244353;

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

int n, m;
int d[N];
ll p[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + d[i];
    }

    if (p[n] % 2 != 0)
    {
        cout << ast(m, n) << "\n";
        return;
    }

    map<ll, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        mp[(p[i] % (p[n] / 2))]++;
    }

    int q1 = 0, q2 = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->se == 1)
        {
            ++q1;
        }
        else
        {
            ++q2;
        }
    }

    int ans = 0;
    for (int q = 0; q <= min(m, q2); ++q)
    {
        int yans = (C(q2, q) * ((C(m, q) * 1LL * f[q]) % M)) % M;
        yans = (yans * 1LL * ast((C(m - q, 2) * 2) % M, q2 - q)) % M;
        yans = (yans * 1LL * ast(m - q, q1)) % M;
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