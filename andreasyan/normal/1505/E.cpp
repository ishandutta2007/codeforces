#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 10;

int n, m;
char a[N][N];

int dp[N][N];
void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);

    int x = 1, y = 1;
    int ans = 0;
    while (1)
    {
        if (a[x][y] == '*')
            ++ans;
        if (x == n && y == m)
            break;
        if (x == n)
        {
            ++y;
            continue;
        }
        if (y == m)
        {
            ++x;
            continue;
        }
        int d = N;
        for (int i = x + 1; i <= n; ++i)
        {
            if (a[i][y] == '*')
            {
                d = i - x;
                break;
            }
        }
        int r = N;
        for (int j = y + 1; j <= m; ++j)
        {
            if (a[x][j] == '*')
            {
                r = j - y;
                break;
            }
        }
        if (r <= d)
        {
            ++y;
        }
        else
        {
            ++x;
        }
    }

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
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}