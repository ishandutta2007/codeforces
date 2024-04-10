#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define inf (1LL << 60)

ll n, k, a, b, i;
ll v[maxN], aux[maxN], pay[maxN];
ll ans = inf;

multiset<ll> S;
ll act, to_add;

ll check(ll rem) {
    ll i, ans;

    for (i = 1; i <= n; i++) {
        aux[i] = v[i];
        pay[i] = 0;

        while (aux[i] % 5 != rem) aux[i]++, pay[i]++;
    }

    ans = inf; act = 0;
    for (i = 1; i <= n; i++) {
        to_add = ((aux[n] - aux[i]) / 5) * a;
        to_add += pay[i] * b;

        act += to_add;
        S.insert(-to_add);

        if (S.size() > k) {
            act += *S.begin();
            S.erase(S.begin());
        }

        if (i >= k)
            ans = min(ans, act - a * k * ((aux[n] - aux[i]) / 5));
    }

    S.clear();
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
    for (i = 1; i <= n; i++)
        scanf("%lld", &v[i]);

    sort(v + 1, v + n + 1);
    for (i = n; i > 0; i--) v[i] -= v[1];

    a = min(a, 5 * b);

    for (i = 0; i < 5; i++)
        ans = min(ans, check(i));

    printf("%lld", ans);


    return 0;
}