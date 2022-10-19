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
const int N = 500005;

int n;
int a[N];

int l[N], r[N], q[N];
int dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
    {
        if (l[a[i]] == 0)
            l[a[i]] = i;
        r[a[i]] = i;
    }

    for (int i = n; i >= 1; --i)
    {
        ++q[a[i]];
        dp[i] = dp[i + 1];
        if (i == l[a[i]])
            dp[i] = max(dp[i], dp[r[a[i]] + 1] + q[a[i]]);
        dp[i] = max(dp[i], q[a[i]]);
    }

    printf("%d\n", n - dp[1]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}