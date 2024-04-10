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

int n, p, k;
char a[N];
int x, y;

int dp[N];

void solv()
{
    scanf("%d%d%d", &n, &p, &k);
    scanf(" %s", (a + 1));
    scanf("%d%d", &x, &y);

    for (int i = n; i >= 1; --i)
    {
        if (a[i] == '1')
        {
            if (i + k <= n)
                dp[i] = dp[i + k];
            else
                dp[i] = 0;
        }
        else
        {
            if (i + k <= n)
                dp[i] = x + dp[i + k];
            else
                dp[i] = x;
        }
    }

    int ans = dp[p];
    for (int i = 1; i <= n; ++i)
    {
        if (n - i < p)
            break;
        ans = min(ans, y * i + dp[i + p]);
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}