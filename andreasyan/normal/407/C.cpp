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
const int N = 100005, M = 1000000007, K = 122;

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
    if (k < 0)
        return 0;
    return ((f[n] * 1LL * rf[k]) % M * rf[n - k]) % M;
}

int n, m;
int a[N];

int p[N][K], h[N][K];

int u[K];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        for (int i = 101; i >= 0; --i)
        {
            p[l][i] = (p[l][i] + C(k, k - (101 - i))) % M;
        }

        for (int i = 101; i >= 0; --i)
        {
            h[r + 1][i] = (h[r + 1][i] + C(k + (r - l), k - (101 - i))) % M;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= 101; ++j)
        {
            u[j] = (u[j] - h[i][j] + M) % M;
        }
        for (int j = 101; j > 0; --j)
        {
            u[j] = (u[j] + u[j - 1]) % M;
        }
        for (int j = 0; j <= 101; ++j)
        {
            u[j] = (u[j] + p[i][j]) % M;
        }

        cout << (u[101] + a[i]) % M << ' ';
    }

    cout << "\n";
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