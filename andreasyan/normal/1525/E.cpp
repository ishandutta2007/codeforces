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
const int N = 22, K = 50004, M = 998244353;

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

int n, k;
int a[N][K];
int f[N];
int rf[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            cin >> a[i][j];
        }
    }

    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    for (int i = 0; i <= n; ++i)
        rf[i] = ast(f[i], M - 2);

    int ans = 0;
    for (int j = 1; j <= k; ++j)
    {
        vector<int> v;
        for (int i = 1; i <= n; ++i)
        {
            v.push_back(a[i][j]);
        }
        sort(all(v));

        int yans = 1;
        for (int i = 0; i < n; ++i)
        {
            yans = (yans * 1LL * max(0, v[i] - 1 - i)) % M;
        }
        yans = (f[n] - yans + M) % M;
        yans = (yans * 1LL * rf[n]) % M;
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}