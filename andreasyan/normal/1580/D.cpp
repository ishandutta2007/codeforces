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
const int N = 4003;
const ll INF = 1000000009000000009;

int n, m;
ll a[N];

int mini[N][N];

ll dp[N][N];
void dfs(int l, int r)
{
    if (l > r)
        return;

    int x = mini[l][r];
    dfs(l, x - 1);
    dfs(x + 1, r);

    int hl = mini[l][x - 1];
    int hr = mini[x + 1][r];

    int ql = (x - l);
    int qr = (r - x);

    for (int i = 0; i <= ql; ++i)
    {
        for (int j = 0; j <= qr; ++j)
        {
            ll s = dp[hl][i] + dp[hr][j];
            s -= i * j * a[x] * 2;
            dp[x][i + j] = max(dp[x][i + j], s);

            s += m * a[x];
            s += i * j * a[x] * 2;
            s -= (i + 1) * (j + 1) * a[x] * 2;
            s += a[x];
            dp[x][i + j + 1] = max(dp[x][i + j + 1], s);
        }
    }
}

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        mini[i][i] = i;
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[j] < a[mini[i][j - 1]])
                mini[i][j] = j;
            else
                mini[i][j] = mini[i][j - 1];
        }
    }

    for (int x = 0; x <= n; ++x)
    {
        for (int i = 0; i <= n; ++i)
        {
            dp[x][i] = -INF;
        }
    }

    dp[0][0] = 0;
    dfs(1, n);

    cout << dp[mini[1][n]][m] << "\n";
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