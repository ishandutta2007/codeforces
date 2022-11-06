#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

ll n, m;
ll ans, step;

ll check(ll limit) {
    ll ans = 0;

    for (ll i = 2; i * i * i <= limit; i++)
        ans += limit / (i * i * i);

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &m);

    ans = 0;
    for (step = (1LL << 60); step > 0; step >>= 1)
        if (check(ans + step) < m)
            ans += step;

    if (check(ans + 1) == m)
        printf("%lld", ans + 1);
    else
        printf("-1");

    return 0;
}