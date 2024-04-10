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
const int N = 5003;

int n;
ll a[N];
int q[N];

int dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        while (a[i] % 2 == 0)
        {
            ++q[i];
            a[i] /= 2;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; --j)
        {
            if (a[j] % a[i] == 0 && (i - j - 1) >= q[i])
                dp[i] = max(dp[i], dp[j] + 1);
            if (a[j] % a[i] == 0 && q[j] + (i - j) == q[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", n - ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    /*int x;
    scanf("%d", &x);
    for (int y = 1; y < x * 3; ++y)
    {
        if (y % 2 == 1)
            continue;
        if ((x % (y / 2)) == 0 && (x / (y / 2)) % 2 == 1)
            printf("%d\n", y);
    }

    printf("\n");
    x *= 2;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            int q = 0;
            while (x % i == 0)
            {
                ++q;
                x /= i;
            }
            printf("%d %d\n", i, q);
        }
    }
    if (x > 1)
        printf("%d %d\n", x, 1);
    return 0;*/
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}