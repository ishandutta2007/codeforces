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
const int N = 200005;

int n;
int a[N];

int q[N];

int dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i < N; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
        q[a[i]]++;

    int ans = 0;
    for (int i = N - 1; i >= 1; --i)
    {
        dp[i] = q[i];
        for (int j = i + i; j < N; j += i)
            dp[i] = max(dp[i], q[i] + dp[j]);
        ans = max(ans, dp[i]);
    }

    printf("%d\n", n - ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}