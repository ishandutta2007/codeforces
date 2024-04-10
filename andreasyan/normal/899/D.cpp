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

ll n;

bool stg(ll x)
{
    if ((x / 2 + x % 2) <= n)
        return true;
    return false;
}

ll gg(ll x)
{
    return max(0LL, min(x / 2, n - (x / 2 + x % 2) + 1));
}

void solv()
{
    scanf("%lld", &n);
    ll x = 0;
    ll t = 1;
    while (1)
    {
        if (stg(x) && !stg(x * 10 + 9))
        {
            if (x == 0)
            {
                printf("%lld\n", n * (n - 1) / 2);
                return;
            }
            ll ans = 0;
            ans += gg(x);
            for (int i = 1; i <= 9; ++i)
            {
                ans += gg(t * i + x);
            }
            printf("%lld\n", ans);
            return;
        }
        x = (x * 10 + 9);
        t *= 10;
    }
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