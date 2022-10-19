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

int dp[N];

void solv()
{
    int n;
    cin >> n;

    dp[0] = 1;
    for (int n = 1; n <= 100000; ++n)
    {
        int l = 0, r = n;
        int q;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m * 2 - 1 >= n - m)
            {
                q = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        dp[n] = q * 2 - 1;
        dp[n] = min(dp[n], dp[n - 1] + 1);
    }

    cout << dp[n] << "\n";
    while (1)
    {
        if (dp[n] == dp[n - 1] + 1)
        {
            cout << n << ' ' << n << "\n";
            --n;
            continue;
        }

        int l = 0, r = n;
        int q;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (m * 2 - 1 >= n - m)
            {
                q = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }

        for (int i = 1; i <= q; ++i)
            cout << i << ' ' << q - i + 1 << "\n";
        for (int i = q + 1; i <= 2 * q - 1; ++i)
            cout << i << ' ' << 3 * q - 1 - i + 1 << "\n";
        return;
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