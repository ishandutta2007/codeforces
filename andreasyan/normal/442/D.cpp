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
const int N = 1000006;

int n;
int p[N];

int dp[N];
int max1[N], max2[N];

int u(int x)
{
    if (x == 1)
        return max1[x];
    return max(max1[x], max2[x] + 1);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 2; i <= n + 1; ++i)
    {
        scanf("%d", &p[i]);
        dp[i] = 1;
        int x = i;
        while (1)
        {
            if (x == 1)
                break;
            if (dp[x] >= max1[p[x]])
            {
                max2[p[x]] = max1[p[x]];
                max1[p[x]] = dp[x];
            }
            else if (dp[x] >= max2[p[x]])
            {
                max2[p[x]] = dp[x];
            }
            else
                break;
            if (u(p[x]) == dp[p[x]])
                break;
            x = p[x];
            dp[x] = u(x);
        }
        printf("%d ", dp[1]);
    }
    printf("\n");
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