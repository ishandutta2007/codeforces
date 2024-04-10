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

#define maxN 200011

ll n, m, k, i;
ll x, s;
ll a[maxN], b[maxN], c[maxN], d[maxN];
ll ans = (1LL << 62) + (1LL << 61);

ll check(ll cnt, ll cost, ll sum) {
    ll pos = upper_bound(d + 1, d + k + 1, sum) - d - 1;
    if (pos > 0) cnt = max(0LL, cnt - c[pos]);
    return cnt * cost;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &m, &k);
    scanf("%lld%lld", &x, &s);
    for (i = 1; i <= m; i++) scanf("%lld", &a[i]);
    for (i = 1; i <= m; i++) scanf("%lld", &b[i]);
    for (i = 1; i <= k; i++) scanf("%lld", &c[i]);
    for (i = 1; i <= k; i++) scanf("%lld", &d[i]);

    ans = check(n, x, s);
    for (i = 1; i <= m; i++) {
        if (b[i] <= s)
            ans = min(ans, check(n, a[i], s - b[i]));
    }

    printf("%lld", ans);


    return 0;
}