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
const int N = 4003;

int n;
int a[N];

bool dp[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; ++i)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= n; ++i)
        dp[i] = false;

    dp[0] = true;
    int u = n * 2 + 1;
    while (u > 1)
    {
        int maxu = 0, maxi = 0;
        for (int i = 1; i < u; ++i)
        {
            if (a[i] > maxu)
            {
                maxu = a[i];
                maxi = i;
            }
        }

        int d = u - maxi;
        u = maxi;

        for (int i = n; i >= 0; --i)
        {
            if (i + d <= n && dp[i])
                dp[i + d] = true;
        }
    }

    if (dp[n])
        printf("YES\n");
    else
        printf("NO\n");
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}