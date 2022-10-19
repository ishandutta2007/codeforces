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
const int N = 50004;
const ll INF = 1000000009000000009;

int n;
ll a[N];

pair<int, ll> dp[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int x;
    cin >> x;
    for (int i = 1; i <= n; ++i)
        a[i] -= x;

    dp[0] = m_p(0, INF);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = m_p(dp[i - 1].fi, INF);
        if (i - 2 >= 0)
            dp[i] = max(dp[i], m_p(dp[i - 2].fi + 1, a[i]));
        if (dp[i - 1].se + a[i] >= 0)
            dp[i] = max(dp[i], m_p(dp[i - 1].fi + 1, min(dp[i - 1].se + a[i], a[i])));
    }

    cout << dp[n].fi << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}