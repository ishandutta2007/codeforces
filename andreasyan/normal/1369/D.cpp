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
const int N = 2000006, M = 1000000007;

int dp[N];

void solv()
{
    dp[3] = 4;
    dp[4] = 4;
    for (int i = 5; i < N; ++i)
    {
        /*int t1 = (4 + 4LL * dp[i - 4] + 4LL * dp[i - 3] + dp[i - 2]) % M;
        int t2 = (2LL * dp[i - 2] + dp[i - 1]) % M;
        if (t1 > t2)
        {
            printf("%d ", i);
        }
        dp[i] = max(t1, t2);
        continue;*/
        if (i % 3 == 0)
            dp[i] = (4 + 4LL * dp[i - 4] + 4LL * dp[i - 3] + dp[i - 2]) % M;
        else
            dp[i] = (2LL * dp[i - 2] + dp[i - 1]) % M;
    }
    //return;
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", dp[x]);
    }
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