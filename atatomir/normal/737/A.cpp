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
#define inf 1LL << 60

int n, k, i;
ll s, t, x;
pair<ll, ll> cars[maxN];
vector<ll> gas;

ll ans, solution;


ll check(ll vol) {
    ll ans = 0;

    for (int i = 1; i < gas.size(); i++) {
        ll dim = gas[i] - gas[i - 1];

        ans += 2 * dim - min(dim, vol - dim);
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%lld%lld", &n, &k, &s, &t);
    for (i = 1; i <= n; i++) scanf("%lld%lld", &cars[i].first, &cars[i].second);
    gas = {0, s};
    for (i = 1; i <= k; i++) {
        scanf("%lld", &x);
        gas.pb(x);
    }

    sort(gas.begin(), gas.end());
    gas.resize(unique(gas.begin(), gas.end()) - gas.begin());

    for (i = 1; i < gas.size(); i++) ans = max(ans, gas[i] - gas[i - 1] - 1);
    for (ll step = (1LL << 33); step > 0; step >>= 1) {
        if (check(ans + step) > t)
            ans += step;
    }

    ans++;
    solution = inf;

    for (i = 1; i <= n; i++) {
        if (cars[i].second < ans) continue;
        solution = min(solution, cars[i].first);
    }

    if (solution == inf) {
        printf("-1");
        return 0;
    }

    printf("%lld", solution);



    return 0;
}