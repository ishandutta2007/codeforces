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
const int N = 502, INF = 1000000009;

int n, m;
char a[N], b[N];

int u[N];

int dp[N][N];
int ndp[N][N];

void solv()
{
    cin >> n >> m;
    cin >> (a + 1);
    cin >> (b + 1);

    for (int k = 0; k < m; ++k)
    {
        for (int q = min(m, k + 1); q >= 0; --q)
        {
            bool z = true;
            for (int i = 1; i <= q; ++i)
            {
                char t;
                if (i == q)
                    t = '0' + ('1' - b[k + 1]);
                else
                    t = b[k - (q - i) + 1];
                if (t != b[i])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                u[k] = q;
                break;
            }
        }
    }
    for (int q = m - 1; q >= 0; --q)
    {
        bool z = true;
        for (int i = 1; i <= q; ++i)
        {
            if (b[m - (q - i)] != b[i])
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            u[m] = q;
            break;
        }
    }

    for (int j = 0; j <= n - m + 1; ++j)
    {
        for (int k = 0; k < m; ++k)
            dp[j][k] = INF;
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n - m + 1; ++j)
        {
            for (int k = 0; k < m; ++k)
                ndp[j][k] = INF;
        }

        for (int j = 0; j <= n - m + 1; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                if (k < m - 1)
                    ndp[j][k + 1] = min(ndp[j][k + 1], dp[j][k] + (a[i] != b[k + 1]));
                else
                    ndp[j + 1][u[m]] = min(ndp[j + 1][u[m]], dp[j][k] + (a[i] != b[k + 1]));

                ndp[j][u[k]] = min(ndp[j][u[k]], dp[j][k] + (a[i] == b[k + 1]));
            }
        }

        for (int j = 0; j <= n - m + 1; ++j)
        {
            for (int k = 0; k < m; ++k)
                dp[j][k] = ndp[j][k];
        }
    }

    for (int j = 0; j <= n - m + 1; ++j)
    {
        int minu = dp[j][0];
        for (int k = 0; k < m; ++k)
            minu = min(minu, dp[j][k]);

        if (minu != INF)
            cout << minu << ' ';
        else
            cout << "-1 ";
    }
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
        solv();
    return 0;
}