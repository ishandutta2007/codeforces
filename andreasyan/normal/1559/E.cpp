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
const int N = 100005, M = 998244353;

int n, m;
int l[55], r[55];

int dp[N];
int p[N];
int solv0(int g)
{
    int m = ::m / g;

    for (int i = 0; i <= m; ++i)
        dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int ul = (l[i] / g) + !!(l[i] % g);
        int ur = (r[i] / g);

        for (int i = 0; i <= m; ++i)
            p[i] = 0;
        for (int s = 0; s <= m; ++s)
        {
            p[min(s + ul, m + 1)] = (p[min(s + ul, m + 1)] + dp[s]) % M;
            p[min(s + ur + 1, m + 1)] = (p[min(s + ur + 1, m + 1)] - dp[s] + M) % M;
        }
        for (int i = 1; i <= m; ++i)
            p[i] = (p[i] + p[i - 1]) % M;
        for (int s = 0; s <= m; ++s)
            dp[s] = p[s];
    }

    int ans = 0;
    for (int s = 0; s <= m; ++s)
        ans = (ans + dp[s]) % M;
    return ans;
}

int ans[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    for (int i = m; i >= 1; --i)
    {
        ans[i] = solv0(i);
        for (int j = i + i; j <= m; j += i)
            ans[i] = (ans[i] - ans[j] + M) % M;
    }

    cout << ans[1] << "\n";
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