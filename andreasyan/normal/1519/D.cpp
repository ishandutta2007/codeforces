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
const int N = 5003;

int n;
int a[N], b[N];

ll dp[N][N];
ll p[N];
ll s[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        dp[i][i] = a[i] * 1LL * b[i];
    for (int d = 2; d <= n; ++d)
    {
        for (int l = 1; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            dp[l][r] = (dp[l + 1][r - 1] + a[l] * 1LL * b[r] + b[l] * 1LL * a[r]);
        }
    }

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i] * 1LL * b[i];
    for (int i = n; i >= 1; --i)
        s[i] = s[i + 1] + a[i] * 1LL * b[i];

    ll ans = 0;
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
        {
            ans = max(ans, p[l - 1] + s[r + 1] + dp[l][r]);
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

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}