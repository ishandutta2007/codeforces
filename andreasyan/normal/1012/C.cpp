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

int dp[N][N], p[N][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int q = 1; q <= n; ++q)
        {
            p[i][q] = dp[i][q] = INF;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
            dp[i][1] = 0;
        else
            dp[i][1] = max(0, a[i - 1] - a[i] + 1);
        for (int q = 2; q <= i; ++q)
        {
            if (i - 2 >= 1)
            {
                dp[i][q] = min(dp[i][q], dp[i - 2][q - 1] + max(0, a[i - 1] - min(a[i], a[i - 2]) + 1));
            }
            if (i - 3 >= 1)
            {
                dp[i][q] = min(dp[i][q], p[i - 3][q - 1] + max(0, a[i - 1] - a[i] + 1));
            }
        }

        for (int q = 1; q <= n; ++q)
        {
            if (i < n)
                p[i][q] = min(p[i - 1][q], dp[i][q] + max(0, a[i + 1] - a[i] + 1));
            else
                p[i][q] = min(p[i - 1][q], dp[i][q]);
        }
    }

    for (int q = 1; q <= n / 2 + n % 2; ++q)
        cout << p[n][q] << ' ';
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}