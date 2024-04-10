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

void solv()
{
    ll l, r, m;
    scanf("%lld%lld%lld", &l, &r, &m);
    for (ll a = l; a <= r; ++a)
    {
        ll mm = m;
        mm %= a;
        if (0 <= mm && mm <= (r - l) && mm != m)
        {
            printf("%lld %lld %lld\n", a, l + mm, l);
            return;
        }
        mm -= a;
        if ((l - r) <= mm && mm <= 0 && mm != m)
        {
            printf("%lld %lld %lld\n", a, r + mm, r);
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}