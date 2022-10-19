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

int n;
int t[N];
int s[N];

void ka()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
}

ll dp[N];

ll solv()
{
    for (int i = 1; i <= n; ++i)
        dp[i] = 0;

    int u = 1;
    while (u < n && t[u + 1] == t[u])
        ++u;

    while (u < n)
    {
        int uu = u + 1;
        while (uu < n && t[uu + 1] == t[uu])
            ++uu;

        for (int j = u; j >= 1; --j)
        {
            if (t[j] == t[uu])
                continue;
            for (int i = u + 1; i <= uu; ++i)
            {
                ll ydpi = dp[i];
                dp[i] = max(dp[i], dp[j] + abs(s[j] - s[i]));
                dp[j] = max(dp[j], ydpi + abs(s[i] - s[j]));
            }
        }

        u = uu;
    }

    ll ans = dp[1];
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);

    return ans;
}

/*ll dp0[N][N];
ll solv0()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp0[i][j] = 0;
        }
    }

    for (int ii = 0; ii < n * n * 2; ++ii)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i <= j)
                {
                    for (int k = j + 1; k <= n; ++k)
                    {
                        if (t[j] != t[k])
                            dp0[j][k] = max(dp0[j][k], dp0[i][j] + abs(s[j] - s[k]));
                    }
                    for (int k = i - 1; k >= 1; --k)
                    {
                        if (t[j] != t[k])
                            dp0[j][k] = max(dp0[j][k], dp0[i][j] + abs(s[j] - s[k]));
                    }
                }
                else
                {
                    for (int k = i + 1; k <= n; ++k)
                    {
                        if (t[j] != t[k])
                            dp0[j][k] = max(dp0[j][k], dp0[i][j] + abs(s[j] - s[k]));
                    }
                }
            }
        }
    }

    ll ans = dp0[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ans = max(ans, dp0[i][j]);
    return ans;
}*/

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
    {
        ka();
        cout << solv() << "\n";
        /*n = 4;
        for (int i = 1; i <= n; ++i)
            t[i] = rnf() % 4 + 1;
        for (int i = 1; i <= n; ++i)
            s[i] = rnf() % 6 + 1;
        if (solv() != solv0())
        {
            cout << "WA\n";
            cout << n << "\n";
            for (int i = 1; i <= n; ++i)
                cout << t[i] << ' ';
            cout << "\n";
            for (int i = 1; i <= n; ++i)
                cout << s[i] << ' ';
            cout << "\n";
            cout << "Incorrect: " << solv() << "\n";
            cout << "Correct: " << solv0() << "\n";
            return 0;
        }*/
    }
    return 0;
}