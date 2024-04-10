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

void por()
{
    int dp[11] = {};
    dp[0] = 1;
    for (int i = 1; i < 11; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            dp[i] += dp[j - 1];
        }
    }

    for (int n = 1; n < 11; ++n)
    {
        int a[11] = {};
        for (int i = 0; i < n; ++i)
            a[i] = i;
        do
        {
            bool z = true;
            for (int i = 0; i < n - 1; ++i)
            {
                if (!(a[i + 1] >= a[i] - 1))
                {
                    z = false;
                    break;
                }
            }
            dp[n] -= z;
        } while (next_permutation(a, a + n));
        if (dp[n] != 0)
        {
            cout << n << "\n";
            cout << dp[n] << "\n";
            return;
        }
    }
}

int n;
ll k;

ll dp[N];

int ans[N];
void solv()
{
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 0;
        for (int j = i; j >= 1; --j)
        {
            dp[i] += dp[j - 1];
            if (dp[i] > k)
                break;
        }
    }

    if (dp[n] < k)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; ++i)
        ans[i] = i;

    int u = 1;
    while (u <= n)
    {
        int s = u;
        while (dp[n - u] < k)
        {
            k -= dp[n - u];
            ++u;
        }
        reverse(ans + s, ans + u + 1);
        ++u;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}