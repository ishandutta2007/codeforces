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
const int N = 2003;

int dp[N];
void pre()
{
    for (int i = 0; i < N; ++i)
        dp[i] = N * 15;
    dp[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i - 6 >= 0)
            dp[i] = min(dp[i], dp[i - 6] + 15);
        if (i - 8 >= 0)
            dp[i] = min(dp[i], dp[i - 8] + 20);
        if (i - 10 >= 0)
            dp[i] = min(dp[i], dp[i - 10] + 25);
    }
    for (int i = N - 2; i >= 0; --i)
        dp[i] = min(dp[i], dp[i + 1]);
}

void solv()
{

    ll n;
    cin >> n;

    ll m = n / 1000 * 1000;
    m = max(m - 1000, 0LL);

    ll ans = (m / 10) * 25;
    n -= m;

    ans += dp[n];

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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}