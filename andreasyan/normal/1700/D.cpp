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
const int N = 200005;

int n;
int a[N];

ll p[N], s[N];

ll dp[N];
ll ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int i = n; i >= 1; --i)
        s[i] = s[i + 1] + a[i];

    for (int i = 1; i <= n; ++i)
    {
        ll x = max(a[i] - (i * 1LL * dp[i - 1] - p[i - 1]), 0LL);
        dp[i] = dp[i - 1] + x / i + !!(x % i);
        dp[i] = min(dp[i], 1000000009LL);

        x = max(s[i] - (i * 1LL * dp[i - 1] - p[i - 1]), 0LL);
        ans[i] = dp[i - 1] + x / i + !!(x % i);
        ans[i] = min(ans[i], 1000000009LL);
    }

    int qq;
    cin >> qq;
    while (qq--)
    {
        int t;
        cin >> t;

        int l = 1, r = n;
        int u = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (ans[m] <= t)
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        cout << u << "\n";
    }
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