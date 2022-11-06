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

ll a[3], b[3], i;
ll ans = 1LL << 62;

ll check(ll fr) {
    ll i;
    ll act = 0;

    memcpy(b, a, sizeof(a));
    for (i = fr; i < 3; i++) {
        if (b[i] == 0) {
            act++;
            continue;
        }

        b[i]--;
    }

    ll maxi = max(b[0], max(b[1], b[2]));
    ll last = 0;
    ll cnt = 0;

    if (maxi == 0) return act;

    for (i = 0; i < 3; i++)
        if (b[i] == maxi)
            last = i, cnt++;

    act += 3 * (maxi - 1) - (b[0] + b[1] + b[2] - cnt);
    act += (last + 1) - cnt;

    return act;
}

ll check_one_day() {
    ll inf = (1LL << 62);

    memcpy(b, a, sizeof(a));

    if (b[0] > 1) return inf;
    if (b[1] > 1) return inf;
    if (b[2] > 1) return inf;

    ll cnt = 0;
    ll i, le, ri;

    le = 2;
    ri = 0;

    for (i = 0; i < 3; i++)
        if (b[i] == 1)
            cnt++, le = min(le, i), ri = max(ri, i);

    return ri - le + 1 - cnt;
}

int main()
{
    //freopen("test.in","r",stdin);

    for (i = 0; i < 3; i++) scanf("%lld", &a[i]);

    ans = min(ans, check(0));
    ans = min(ans, check(1));
    ans = min(ans, check(2));

    ans = min(ans, check_one_day());
    printf("%lld", ans);

    return 0;
}