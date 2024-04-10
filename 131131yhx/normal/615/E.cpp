#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    scanf("%lld", &n);
    ll ans = 0, X, Y = 0;
    for(ll l = 0, r = 1000000000ll; l <= r;)
    {
        ll mid = l + r >> 1;
        if(mid * (mid + 1) * 3 <= n) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    X = ans * 2;
    n -= ans * (ans + 1) * 3;
    ans++;
    if(n == 0)
    {
        printf("%lld %lld\n", X, Y);
        return 0;
    }
    n--, X += 1, Y += 2;
    if(n <= ans - 1)
    {
        printf("%lld %lld\n", X - n, Y + 2 * n);
        return 0;
    }
    X -= (ans - 1), Y += (ans - 1) * 2, n -= (ans - 1);
    if(n <= ans)
    {
        printf("%lld %lld\n", X - 2 * n, Y);
        return 0;
    }
    X -= ans * 2, n -= ans;
    if(n <= ans)
    {
        printf("%lld %lld\n", X - n, Y - 2 * n);
        return 0;
    }
    X -= ans, Y -= ans * 2, n -= ans;
    if(n <= ans)
    {
        printf("%lld %lld\n", X + n, Y - 2 * n);
        return 0;
    }
    X += ans, Y -= ans * 2, n -= ans;
    if(n <= ans)
    {
        printf("%lld %lld\n", X + 2 * n, Y);
        return 0;
    }
    X += ans * 2, n -= ans;
    printf("%lld %lld\n", X + n, Y + 2 * n);
    return 0;
}