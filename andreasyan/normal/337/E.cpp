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
const int N0 = 10, N3 = 60000;
const ll INF = 1000000009003;

int n;
ll a[N0];

int q[N0];

int dp[N3];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i)
    {
        ll x = a[i];
        for (ll j = 2; j * j <= x; ++j)
        {
            while (x % j == 0)
            {
                ++q[i];
                x /= j;
            }
        }
        if (x > 1)
            ++q[i];
    }

    for (int u = 1; u < N3; ++u)
        dp[u] = N3;
    for (int x = 0; x < (1 << n); ++x)
    {
        for (int y = x; ; y = ((y - 1) & x))
        {
            int u = 0;
            int ast = 1;
            for (int i = 0; i < n; ++i)
            {
                if ((x & (1 << i)))
                {
                    if ((y & (1 << i)))
                        u += ast * 2;
                    else
                        u += ast;
                }
                ast *= 3;
            }

            for (int i = 0; i < n; ++i)
            {
                if (!(x & (1 << i)))
                {
                    for (int z = y; ; z = ((z - 1) & y))
                    {
                        ll k = 1;
                        for (int j = 0; j < n; ++j)
                        {
                            if ((z & (1 << j)))
                            {
                                if (k > (long double)INF / a[j])
                                    k = INF;
                                else
                                    k *= a[j];
                            }
                        }
                        if (a[i] % k != 0)
                            continue;

                        int qq = q[i] + 1;
                        if (q[i] == 1)
                            --qq;
                        int ast = 1;
                        int uu = u;
                        for (int j = 0; j < n; ++j)
                        {
                            if (i == j)
                                uu += ast * 2;
                            if ((z & (1 << j)))
                            {
                                uu -= ast;
                                qq -= q[j];
                            }
                            ast *= 3;
                        }

                        if (uu == 1 + 3 + 9 + 27)
                            printf("What?\n");
                        dp[uu] = min(dp[uu], dp[u] + qq);

                        if (z == 0)
                            break;
                    }
                }
            }
            if (y == 0)
                break;
        }
    }

    int ans = N3;
    for (int y = 0; y < (1 << n); ++y)
    {
        int q = 0;
        int u = 0;
        int ast = 1;
        for (int i = 0; i < n; ++i)
        {
            if ((y & (1 << i)))
            {
                ++q;
                u += ast * 2;
            }
            else
            {
                u += ast;
            }
            ast *= 3;
        }
        if (q > 1)
            ans = min(ans, dp[u] + 1);
        else
            ans = min(ans, dp[u]);
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}