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
const int N = 102;

bitset<N * N> dp[N][N];
void pre()
{
    for (int x = 1; x <= 100; ++x)
    {
        for (int y = 1; y <= 100; ++y)
        {
            if (x == 1 && y == 1)
            {
                dp[x][y][0] = 1;
            }
            else if (x == 1)
            {
                dp[x][y] = (dp[x][y - 1] << x);
            }
            else if (y == 1)
            {
                dp[x][y] = (dp[x - 1][y] << y);
            }
            else
            {
                dp[x][y] = (dp[x][y - 1] << x);
                dp[x][y] = (dp[x - 1][y] << y);
            }
        }
    }
}

void solv()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (dp[n][m][k])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}