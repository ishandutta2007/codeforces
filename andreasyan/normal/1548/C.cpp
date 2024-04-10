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
const int N = 3000006, M = 1000000007;

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
    return ((f[n] * 1LL * rf[k]) % M * rf[n - k]) % M;
}

int n;
int ans[N][3];

void solv()
{
    cin >> n;
    int qq;
    cin >> qq;

    for (int i = 1; i <= n * 3; ++i)
        ans[1][i % 3] = (ans[1][i % 3] + i) % M;

    int r3 = ast(3, M - 2);

    for (int x = 2; x <= 3 * n; ++x)
    {
        ans[x][1] = C(3 * n + 1, x + 1);
        ans[x][1] = (ans[x][1] - ans[x - 1][2] + M) % M;
        ans[x][1] = (ans[x][1] - (ans[x - 1][1] * 2) % M + M) % M;
        ans[x][1] = (ans[x][1] * 1LL * r3) % M;

        ans[x][2] = (ans[x - 1][1] + ans[x][1]) % M;
        ans[x][0] = (ans[x - 1][2] + ans[x][2]) % M;
    }

    while (qq--)
    {
        int x;
        cin >> x;

        cout << ans[x][0] << "\n";
    }
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