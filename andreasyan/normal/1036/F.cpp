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
const int M = 62, m = 60;
const ll INF = 1000000009000000009;

int q[M];

ll ast[M][M];

ll uu[M];

void pre()
{
    for (int i = 1; i <= m; ++i)
    {
        ast[i][0] = 1;
        for (int j = 1; j <= m; ++j)
        {
            if (ast[i][j - 1] < (double)INF / i)
                ast[i][j] = ast[i][j - 1] * i;
            else
                ast[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        int x = i;
        for (int j = 2; j * j <= x; ++j)
        {
            if (x % j == 0)
            {
                ++q[i];
                x /= j;
                if (x % j == 0)
                {
                    q[i] = -1;
                    break;
                }
            }
        }
        if (q[i] == -1)
            continue;
        if (x > 1)
            ++q[i];
        ++q[i];
    }
    for (int j = 1; j <= m; ++j)
    {
        if (q[j] == -1)
            continue;
        if (j <= 15)
        {
            ll l = 2, r = INF;
            uu[j] = 1;
            while (l <= r)
            {
                ll m = (l + r) / 2;
                ll k = 1;
                for (int i = 1; i <= j; ++i)
                {
                    if (k < (double)(INF + 4) / m)
                        k *= m;
                    else
                    {
                        k = INF + 4;
                        break;
                    }
                }
                if (k <= INF)
                {
                    uu[j] = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
        }
    }
}

void solv()
{
    ll n;
    scanf("%lld", &n);
    ll ans = 0;
    for (int j = 1; j <= m; ++j)
    {
        if (q[j] == -1)
            continue;
        if (j <= 15)
        {
            ll l = 2, r = uu[j];
            ll u = 1;
            while (l <= r)
            {
                ll m = (l + r) / 2;
                ll k = 1;
                for (int i = 1; i <= j; ++i)
                {
                    k *= m;
                }
                if (k <= n)
                {
                    u = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            if (q[j] % 2 == 1)
                ans += (u - 1);
            else
                ans -= (u - 1);
        }
        else
        {
            for (int i = 1; ; ++i)
            {
                if (ast[i][j] > n)
                {
                    if (q[j] % 2 == 1)
                        ans += (i - 2);
                    else
                        ans -= (i - 2);
                    break;
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}