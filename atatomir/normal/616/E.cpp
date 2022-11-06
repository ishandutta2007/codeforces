#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long

#define mod 1000000007
#define def 10000000

ll n, m, i, cnt;
ll ans;
ll last;

ll get_pos() {
    ll ans = 0;
    for (ll step = 1LL << 60; step; step >>= 1) {
        if (ans + step <= m)
            if ( n / (ans + step) > cnt)
                ans += step;
    }

    return ans;
}

int main()
{
    //freopen("test.in", "r", stdin);

    scanf("%I64d %I64d", &n, &m);

    if (m > n) {
       ans = ((n % mod) * ((m - n)% mod)) % mod;
       m = n;
    }

    last = m;
    cnt = 1;

    while (last > def) {
        ll pos = get_pos();

        ll dim = (last - pos);
        ll sum = (last + pos + 1);

        ll aux;
        if (dim % 2 == 0)
            aux = ((dim / 2) % mod) * (sum % mod);
        else
            aux = ((sum / 2) % mod) * (dim % mod);
        aux %= mod;

        ans += mod + (((n % mod) * (dim % mod)) % mod) - ((aux * cnt) % mod);
        ans %= mod;

        last = pos;
        cnt++;
    }

    for (i = 2; i <= last; i++) {
        ans += n % i;
        if (ans >= mod) ans -= mod;
    }

    printf("%I64d", ans);

    return 0;
}