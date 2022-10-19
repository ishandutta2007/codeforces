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
const int N = 8003;

int n;
char a[N];

int q[N];

int dp[N];

int p[N];

void solv()
{
    scanf(" %s", a);
    n = strlen(a);
    for (int i = 1; i <= n; ++i)
    {
        int x = i;
        while (x)
        {
            ++q[i];
            x /= 10;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        p[i] = 0;
        for (int j = i + 1; j < n; ++j)
        {
            int k = p[j - 1];
            while (k > 0 && a[i + k] != a[j])
                k = p[i + k - 1];
            if (a[i + k] == a[j])
                ++k;
            p[j] = k;
        }
        dp[i] = N;
        for (int j = i; j < n; ++j)
        {
            if ((j - i + 1) % (j - i + 1 - p[j]) == 0)
                dp[i] = min(dp[i], dp[j + 1] + (j - i + 1 - p[j]) + q[(j - i + 1) / (j - i + 1 - p[j])]);
            else
                dp[i] = min(dp[i], dp[j + 1] + (j - i + 1) + q[1]);
        }
    }
    printf("%d\n", dp[0]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}