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
const int N = 44;

int n, A, B;
char a[N];

bool dp[N][N][N][N];
pair<char, int> p[N][N][N][N];

char s[N];

void solv()
{
    cin >> n >> A >> B;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
        a[i] -= '0';

    memset(dp, false, sizeof dp);

    dp[0][0][0][0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int r = 0; r <= i; ++r)
        {
            for (int x = 0; x < A; ++x)
            {
                for (int y = 0; y < B; ++y)
                {
                    if (!dp[i][r][x][y])
                        continue;
                    dp[i + 1][r + 1][(x * 10 + a[i + 1]) % A][y]  = true;
                    p[i + 1][r + 1][(x * 10 + a[i + 1]) % A][y] = m_p('R', x);
                    dp[i + 1][r][x][(y * 10 + a[i + 1]) % B] = true;
                    p[i + 1][r][x][(y * 10 + a[i + 1]) % B] = m_p('B', y);
                }
            }
        }
    }

    int ans = N;
    for (int r = 1; r < n; ++r)
    {
        if (dp[n][r][0][0])
        {
            ans = min(ans, abs(r - (n - r)));
        }
    }

    if (ans == N)
    {
        cout << "-1\n";
        return;
    }

    for (int r = 1; r < n; ++r)
    {
        if (dp[n][r][0][0] && ans == abs(r - (n - r)))
        {
            s[n] = 0;
            int x = 0;
            int y = 0;
            for (int i = n; i >= 1; --i)
            {
                pair<char, int> u = p[i][r][x][y];
                s[i - 1] = u.fi;
                if (u.fi == 'R')
                {
                    --r;
                    x = u.se;
                }
                else
                {
                    y = u.se;
                }
            }
            cout << s << "\n";
            return;
        }
    }

    assert(false);
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