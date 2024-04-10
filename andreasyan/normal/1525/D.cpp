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
const int N = 5003, INF = 1000000009;

int n;
int a[N];

vector<int> v;
int dp[N][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
            v.push_back(i);
    }
    a[n + 1] = 1;

    for (int i = 0; i <= sz(v); ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
        {
            dp[i][j] = INF;
        }
    }

    dp[0][1] = 0;

    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = 1; j <= n + 1; ++j)
        {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            if (a[j] == 0)
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(v[i] - j));
        }
    }

    int ans = INF;
    for (int j = 1; j <= n + 1; ++j)
        ans = min(ans, dp[sz(v)][j]);

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