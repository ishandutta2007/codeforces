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
const ll INF = 1000000009000000009;

int n;
ll r1, r2, r3, d;
ll a[N];

ll dp[N];
void ubd(ll& x, ll y)
{
    x = min(x, y);
}

ll s[N];
void solv()
{
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        dp[i] = INF;

    for (int i = 0; i < n; ++i)
    {
        if (i + 1 <= n)
        {
            ubd(dp[i + 1], dp[i] + d * !!(i)
                + a[i + 1] * r1 + r3);
        }
        if (i + 2 <= n)
        {
            ubd(dp[i + 2], dp[i] + d * !!(i) + d * 3
                + min(r1 * (a[i + 1] + 1), r2)
                + min(r1 * (a[i + 2] + 1), r2) + r1 * 2);
        }
        if (i + 3 <= n)
        {
            ubd(dp[i + 3], dp[i] + d * !!(i) + d * 6
                + min(r1 * (a[i + 1] + 1), r2)
                + min(r1 * (a[i + 2] + 1), r2)
                + min(r1 * (a[i + 3] + 1), r2) + r1 * 3);
        }
    }

    s[n] = min(a[n] * r1 + r3,
               min(r1 * (a[n] + 1), r2) + 2 * d + r1);
    for (int i = n - 1; i >= 1; --i)
    {
        s[i] += s[i + 1];
        s[i] += min(r1 * (a[i] + 1), r2) + 2 * d + r1;
    }

    ll ans = dp[n];
    for (int i = 0; i < n - 1; ++i)
    {
        ubd(ans, dp[i] + !!(i) * d + s[i + 1]);
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
        solv();
    return 0;
}