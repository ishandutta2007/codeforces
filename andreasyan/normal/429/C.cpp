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
const int N = 26;

int n, m;
int a[N];

bool dp[N][(1 << N / 2)][N];

bool solv()
{
    scanf("%d", &n);
    int qq = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x == 1)
            ++qq;
        else
            a[m++] = x;
    }
    n = m;
    m = qq;
    if (m < n)
        return false;
    if (m == 1 && n == 0)
        return true;
    sort(a, a + n);
    dp[0][0][m] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int x = 0; x < (1 << i); ++x)
        {
            for (int q = 0; q <= m; ++q)
            {
                if (!dp[i][x][q])
                    continue;
                for (int y = x; ; y = ((y - 1) & x))
                {
                    int s = 0;
                    int z = 0;
                    for (int j = 0; j < n; ++j)
                    {
                        if ((y & (1 << j)))
                        {
                            ++z;
                            s += a[j];
                        }
                    }
                    if (s > (a[i] - 1))
                    {
                        if (y == 0)
                            break;
                        continue;
                    }
                    if (s + q < (a[i] - 1))
                    {
                        if (y == 0)
                            break;
                        continue;
                    }
                    z += ((a[i] - 1) - s);
                    if (z >= 2)
                        dp[i + 1][((x ^ y) | (1 << i))][q - ((a[i] - 1) - s)] = true;
                    if (y == 0)
                        break;
                }
            }
        }
    }
    return dp[n][(1 << (n - 1))][0];
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    if (solv())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}