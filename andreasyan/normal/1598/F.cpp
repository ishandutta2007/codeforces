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
const int N = 22, M = 400005;

int n;
int minu[N][M], q[N][M], s[N];

int m[N];
char a[M];

int dp[(1 << N)];

void solv()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        m[i] = strlen(a);

        for (int j = 0; j < m[i]; ++j)
        {
            if (a[j] == '(')
                ++s[i];
            else
                --s[i];

            if (j)
            {
                minu[i][j] = minu[i][j - 1];
                q[i][j] = q[i][j - 1];
            }
            else
            {
                minu[i][j] = s[i];
                q[i][j] = 0;
            }

            if (s[i] < minu[i][j])
            {
                minu[i][j] = s[i];
                q[i][j] = 1;
            }
            else if (s[i] == minu[i][j])
                ++q[i][j];
        }
    }

    for (int x = 0; x < (1 << n); ++x)
        dp[x] = -M;
    dp[0] = 0;

    int ans = 0;
    for (int x = 0; x < (1 << n); ++x)
    {
        if (dp[x] < 0)
            continue;

        ans = max(ans, dp[x]);

        int ss = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ss += s[i];
        }

        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                continue;

            if (ss + minu[i][m[i] - 1] < 0)
            {
                int l = 0, r = m[i] - 1;
                int u = -1;
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    if (minu[i][mid] >= -ss)
                    {
                        u = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }
                if (u != -1)
                {
                    assert(minu[i][u] == -ss);
                    ans = max(ans, dp[x] + q[i][u]);
                }
                continue;
            }

            if (ss + minu[i][m[i] - 1] > 0)
                dp[(x | (1 << i))] = max(dp[(x | (1 << i))], dp[x]);
            else
                dp[(x | (1 << i))] = max(dp[(x | (1 << i))], dp[x] + q[i][m[i] - 1]);
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
    {
        solv();
    }
    return 0;
}