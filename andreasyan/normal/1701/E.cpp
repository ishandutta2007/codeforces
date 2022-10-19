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
const int N = 5003;

int n, m;
char s[N];
char t[N];

int dp[N][3];
int ndp[N][3];

void minh(int& x, int y)
{
    x = min(x, y);
}

void solv()
{
    cin >> n >> m;
    cin >> (s + 1);
    cin >> (t + 1);

    for (int j = 1; j <= m + 1; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            dp[j][k] = N * N;
        }
    }

    dp[1][0] = 1;
    dp[1][1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m + 1; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                ndp[j][k] = N * N;
            }
        }
        for (int j = 1; j <= m + 1; ++j)
        {
            minh(dp[j][1], dp[j][0]);
            minh(dp[j][2], dp[j][1]);

            minh(ndp[j][0], dp[j][0] + 2);
            if (j <= m && s[i] == t[j])
                minh(ndp[j + 1][0], dp[j][0] + 1);

            if (j <= m && s[i] == t[j])
                minh(ndp[j + 1][1], dp[j][1]);

            minh(ndp[j][2], dp[j][2] + 1);
            if (j <= m && s[i] == t[j])
                minh(ndp[j + 1][2], dp[j][2] + 1);
        }
        for (int j = 1; j <= m + 1; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                dp[j][k] = ndp[j][k];
            }
        }
    }

    int ans = min(dp[m + 1][0], min(dp[m + 1][1], dp[m + 1][2]));
    if (ans == N * N)
        cout << "-1\n";
    else
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}