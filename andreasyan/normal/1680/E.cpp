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
const int N = 200005, INF = 1000000009;

int n;
char a[2][N];

int dp[2][N];

void solv()
{
    cin >> n;
    for (int i = 0; i < 2; ++i)
        cin >> a[i];

    int s;
    for (int j = 0; j < n; ++j)
    {
        if (a[0][j] == '.' && a[1][j] == '.')
            continue;
        s = j;
        break;
    }

    int f;
    for (int j = n - 1; j >= 0; --j)
    {
        if (a[0][j] == '.' && a[1][j] == '.')
            continue;
        f = j;
        break;
    }

    if (a[0][s] == '*' && a[1][s] == '*')
    {
        dp[0][s] = 1;
        dp[1][s] = 1;
    }
    else if (a[0][s] == '*')
    {
        dp[0][s] = 0;
        dp[1][s] = 1;
    }
    else if (a[1][s] == '*')
    {
        dp[0][s] = 1;
        dp[1][s] = 0;
    }
    else
        assert(false);

    for (int j = s; j < f; ++j)
    {
        dp[0][j] = min(dp[0][j], dp[1][j] + 1);
        dp[1][j] = min(dp[1][j], dp[0][j] + 1);

        if (a[0][j + 1] == '.' && a[1][j + 1] == '.')
        {
            dp[0][j + 1] = dp[0][j] + 1;
            dp[1][j + 1] = dp[1][j] + 1;
        }
        else if (a[0][j + 1] == '*' && a[1][j + 1] == '.')
        {
            dp[0][j + 1] = dp[0][j] + 1;
            dp[1][j + 1] = min(dp[0][j] + 2, dp[1][j] + 2);
        }
        else if (a[0][j + 1] == '.' && a[1][j + 1] == '*')
        {
            dp[0][j + 1] = min(dp[0][j] + 2, dp[1][j] + 2);
            dp[1][j + 1] = dp[1][j] + 1;
        }
        else
        {
            dp[0][j + 1] = dp[1][j + 1] = min(dp[0][j] + 2, dp[1][j] + 2);
        }
    }

    cout << min(dp[0][f], dp[1][f]) << "\n";
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