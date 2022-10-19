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
const int N = 200005, M = 998244353;

int n;
int a[N];

int dp[N];
int p[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    stack<int> s;
    s.push(1);
    dp[1] = a[1] % M;
    p[1] = dp[1];
    for (int i = 2; i <= n; ++i)
    {
        while (!s.empty() && a[i] < a[s.top()])
        {
            s.pop();
        }

        if (!s.empty())
            dp[i] = ((p[i - 1] - p[s.top() - 1]) * 1LL * a[i]) % M;
        else
            dp[i] = (p[i - 1] * 1LL * a[i]) % M;
        if ((i - 1) % 2 == 0)
            dp[i] *= -1;

        if (!s.empty())
        {
            if (s.top() % 2 == i % 2)
                dp[i] += dp[s.top()];
            else
                dp[i] -= dp[s.top()];
        }
        else
        {
            if (i % 2 == 0)
                dp[i] -= a[i];
            else
                dp[i] += a[i];
        }
        dp[i] %= M;

        s.push(i);
        p[i] = p[i - 1];
        if (i % 2 == 1)
            p[i] += dp[i];
        else
            p[i] -= dp[i];
        p[i] %= M;
    }

    dp[n] = (dp[n] + M) % M;
    cout << dp[n] << "\n";
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