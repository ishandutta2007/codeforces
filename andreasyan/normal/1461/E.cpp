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

ll k, l, r, t, x, y;

bool c[1000006];
bool solv()
{
    scanf("%lld%lld%lld%lld%lld%lld", &k, &l, &r, &t, &x, &y);

    if (x >= y)
    {
        if (k + y <= r)
            k += y;

        if ((k - l - x) < 0)
            return false;
        if (x == y)
            return true;

        // k - (x - y) * (t - 1) - x >= l
        if ((k - l - x) / (x - y) + 1 > (t - 1))
            return true;
        return false;
    }

    if (y > (r - l + 1))
    {
        if ((k - l) / x + 1 > t)
            return true;
        return false;
    }

    if (y <= r - (l + x - 1))
        return true;

    ll q = (k - l) / x;
    k -= q * x;
    t -= q;

    while (1)
    {
        if (t <= 0)
            return true;
        if (c[k - l])
            return true;
        c[k - l] = true;

        if (k + y > r)
            return false;

        k += y;
        k -= x;
        t -= 1;

        ll q = (k - l) / x;
        k -= q * x;
        t -= q;
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    if (solv())
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}