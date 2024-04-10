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
const int N = 200004;
const ll INF = 1000000009000000009;

int n;
char s[N];
int a[N];

ll dp[N][2];
void solv()
{
    cin >> n;
    cin >> (s + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    dp[n + 1][0] = 0;
    dp[n + 1][1] = -INF;
    for (int i = n; i >= 1; --i)
    {
        if (s[i] == '0')
        {
            dp[i][1] = -INF;
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + a[i]);
        }
        else
        {
            dp[i][1] = max(dp[i + 1][0], dp[i + 1][1] + a[i]);
            dp[i][0] = dp[i + 1][0] + a[i];
        }
    }
    cout << dp[1][0] << "\n";
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