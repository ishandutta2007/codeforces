#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e3 + 7;
const int M = 1e9 + 7;

int dp[N][N];

inline int add(int a, int b)
{
    return (a + b >= M ? a + b - M : a + b);
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n, h;
    scanf("%d%d", &n, &h);
    vector <int> a(n);
    for (int &x : a)
    {
        scanf("%d", &x);
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int op = 0; op <= h; op++)
        {
            if (a[i] + op == h)
            {
                if (op)
                {
                    dp[i + 1][op - 1] = add(dp[i + 1][op - 1], mul(dp[i][op], op));
                }
                dp[i + 1][op] = add(dp[i + 1][op], dp[i][op]);
            }
            else if (a[i] + op + 1 == h)
            {
                dp[i + 1][op] = add(dp[i + 1][op], mul(dp[i][op], op + 1));
                dp[i + 1][op + 1] = add(dp[i + 1][op + 1], dp[i][op]);
            }
        }
    }
    printf("%d\n", dp[n][0]);
}