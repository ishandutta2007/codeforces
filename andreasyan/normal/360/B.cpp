#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 2003;

int n, k;
int a[N];

int dp[N];
bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = (i - 1);
        for (int j = i - 1; j >= 1; --j)
        {
            if (abs(a[i] - a[j]) <= (i - j) * 1LL * x)
                dp[i] = min(dp[i], dp[j] + (i - j - 1));
        }
        if (dp[i] + (n - i) <= k)
            return true;
    }
    return false;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int l = 0, r = 2000000000;
    int ans;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
    return 0;
}