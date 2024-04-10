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
const int N = 1000006, INF = 1000000009;

int n;
int a[N];

int dp[N][2];

int p[N][2];

void minh(int& x, int& px, int y, int u)
{
    if (y < x)
    {
        x = y;
        px = u;
    }
}

bool solv()
{
    dp[1][0] = dp[1][1] = -INF;
    for (int i = 2; i <= n; ++i)
        dp[i][0] = dp[i][1] = INF;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i + 1])
        {
            minh(dp[i + 1][0], p[i + 1][0], dp[i][0], 0);
        }
        if (dp[i][0] < a[i + 1])
        {
            minh(dp[i + 1][0], p[i + 1][0], a[i], 0);
        }
        if (dp[i][0] < -a[i + 1])
        {
            minh(dp[i + 1][1], p[i + 1][1], a[i], 0);
        }

        if (-a[i] < a[i + 1])
        {
            minh(dp[i + 1][0], p[i + 1][0], dp[i][1], 1);
        }
        if (-a[i] < -a[i + 1])
        {
            minh(dp[i + 1][1], p[i + 1][1], dp[i][1], 1);
        }
        if (dp[i][1] < a[i + 1])
        {
            minh(dp[i + 1][0], p[i + 1][0], -a[i], 1);
        }
        if (dp[i][1] < -a[i + 1])
        {
            minh(dp[i + 1][1], p[i + 1][1], -a[i], 1);
        }
    }

    if (dp[n][0] != INF || dp[n][1] != INF)
    {
        int u;
        if (dp[n][0] != INF)
            u = 0;
        else
            u = 1;

        for (int i = n; i >= 1; --i)
        {
            if (u == 1)
                a[i] *= -1;
            u = p[i][u];
        }

        cout << "YES\n";
        for (int i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << "\n";

        return true;
    }

    cout << "NO\n";
    return false;
}

bool solv0()
{
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (i - 1))))
                a[i] *= -1;
        }

        bool z = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                for (int k = j + 1; k <= n; ++k)
                {
                    if (a[i] > a[j] && a[j] > a[k])
                    {
                        z = false;
                        break;
                    }
                }
                if (!z)
                    break;
            }
            if (!z)
                break;
        }
        if (z)
        {
            return true;
            for (int i = 1; i <= n; ++i)
            {
                if ((x & (1 << (i - 1))))
                    a[i] *= -1;
            }
            return true;
        }

        for (int i = 1; i <= n; ++i)
        {
            if ((x & (1 << (i - 1))))
                a[i] *= -1;
        }
    }
    return false;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 100;
    /*while (tt--)
    {
        n = 15;
        for (int i = 1; i <= n; ++i)
            a[i] = i;
        for (int i = n; i >= 1; --i)
            swap(a[i], a[rnf() % i + 1]);

        if (solv() != solv0())
        {
            cout << "WA\n";
            cout << n << "\n";
            for (int i = 1; i <= n; ++i)
                cout << a[i] << ' ';
            cout << endl;
            solv();
            return 0;
        }
    }
    cout << "OK\n";
    return 0;*/

    cin >> tt;
    while (tt--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        solv();
    }
    return 0;
}