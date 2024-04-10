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

ll p, q;

void solv()
{
    scanf("%lld%lld", &p, &q);
    if (p % q != 0)
        printf("%lld\n", p);
    else
    {
        ll ans = 1;
        for (ll i = 2; i * i <= q; ++i)
        {
            if (q % i == 0)
            {
                ll u = p;
                while (u % q == 0)
                    u /= i;
                ans = max(ans, u);
                while (q % i == 0)
                    q /= i;
            }
        }
        if (q > 1)
        {
            ll u = p;
            while (u % q == 0)
                u /= q;
            ans = max(ans, u);
        }
        printf("%lld\n", ans);
    }
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