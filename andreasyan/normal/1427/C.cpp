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
const int N = 100005;

int n, r;
int t[N], x[N], y[N];

int dp[N], p[N];

void solv()
{
    scanf("%d%d", &r, &n);
    t[0] = 0;
    x[0] = 1;
    y[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &t[i], &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = -N;
        for (int j = i - 1; j >= max(0, i - r * 2); --j)
        {
            if (t[j] + abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (i - r * 2 >= 0)
            dp[i] = max(dp[i], p[i - r * 2] + 1);
        p[i] = max(p[i - 1], dp[i]);
    }
    printf("%d\n", p[n]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}