#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

ll n, l, r, i, cnt;
vector<ll> dp;

ll solve(ll n) {
    if (n <= 1) return 1;

    ll aux = solve(n / 2);
    dp.pb(aux);

    return aux * 2 + 1;
}

ll get_pos(ll n, ll ve, ll pos) {
    if (ve == 0) return n & 1;

    if (pos <= dp[ve - 1])
        return get_pos(n / 2, ve - 1, pos);

    if (pos == dp[ve - 1] + 1)
        return n & 1;

    return get_pos(n / 2, ve - 1, pos - (dp[ve - 1] + 1));
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &n, &l, &r);

    dp.pb(solve(n));
    for (i = l; i <= r; i++) {
        cnt += get_pos(n, dp.size() - 1, i);
    }

    printf("%lld", cnt);


    return 0;
}