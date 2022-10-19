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
const int N = 103, INF = 1000000009;

int n;
double c, T;
pair<int, int> a[N];

double ast[N];
double dp[N * 10][N];

double maxu[N];

void solv()
{
    cin >> n;
    cin >> c >> T;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    for (int i = 0; i <= n * 10; ++i)
    {
        for (int q = 0; q <= n; ++q)
            dp[i][q] = INF;
    }
    dp[0][0] = 0;

    ast[0] = 1;
    for (int i = 1; i <= n; ++i)
        ast[i] = (ast[i - 1] * 0.9);

    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = p; j >= 0; --j)
        {
            for (int q = i - 1; q >= 0; --q)
            {
                dp[j + a[i].se][q + 1] = min(dp[j + a[i].se][q + 1],
                                             dp[j][q] + a[i].fi / ast[(q + 1)]);
            }
        }
        p += a[i].se;
    }

    for (int q = 0; q <= n; ++q)
    {
        double l = 0, r = T;
        for (int ii = 0; ii < 150; ++ii)
        {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            if ((m1 * c + 1) * (T - m1) - q * 10 * (m1 * c + 1) > (m2 * c + 1) * (T - m2) - q * 10 * (m2 * c + 1))
                r = m2;
            else
                l = m1;
        }
        maxu[q] = max((l * c + 1) * (T - l) - q * 10 * (l * c + 1),
                            (r * c + 1) * (T - r) - q * 10 * (r * c + 1));
    }

    for (int j = p; j >= 0; --j)
    {
        for (int q = 0; q <= n; ++q)
        {
            if (dp[j][q] <= maxu[q])
            {
                cout << j << "\n";
                return;
            }
        }
    }
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