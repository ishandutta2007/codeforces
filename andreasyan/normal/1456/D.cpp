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
#define int long long
const int N = 5003, INF = 1000000009000000009;

int n;
int t[N], x[N];

bool dp0[N][N];
int dp1[N][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i] >> x[i];
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            dp1[i][j] = INF;
        }
    }
    dp0[0][0] = true;

    for (int i = 0; i < n; ++i)
    {
        if (dp0[i][0])
        {
            if (t[i] + abs(x[i] - x[i + 1]) <= t[i + 1])
                dp0[i + 1][0] = true;
            for (int j = i + 1; j <= n; ++j)
                dp1[i][j] = min(dp1[i][j], t[i] + abs(x[i] - x[j]));
        }
        if (dp0[i][i + 1])
        {
            if (i + 1 == n)
            {
                cout << "YES\n";
                return;
            }
            if (t[i] + abs(x[i] - x[i + 2]) <= t[i + 2])
                dp0[i + 2][0] = true;
            for (int j = i + 2; j <= n; ++j)
                dp1[i + 1][j] = min(dp1[i + 1][j], max(t[i + 1], t[i] + abs(x[i] - x[j])));
        }
        for (int j = i + 2; j <= n; ++j)
        {
            if (dp0[i][j] && t[i] + abs(x[i] - x[i + 1]) <= t[i + 1])
                dp0[i + 1][j] = true;
        }

        if (dp1[i][i + 1] <= t[i + 1])
        {
            if (i + 1 == n)
            {
                cout << "YES\n";
                return;
            }
            if (dp1[i][i + 1] + abs(x[i + 1] - x[i + 2]) <= t[i + 2])
                dp0[i + 2][0] = true;
            for (int j = i + 2; j <= n; ++j)
                dp1[i + 1][j] = min(dp1[i + 1][j], max(t[i + 1], dp1[i][i + 1] + abs(x[i + 1] - x[j])));
        }
        for (int j = i + 2; j <= n; ++j)
        {
            if (dp1[i][j] > t[j])
                continue;
            if (dp1[i][j] + abs(x[j] - x[i + 1]) <= t[i + 1])
                dp0[i + 1][j] = true;
        }
    }

    if (dp0[n][0])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main()
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