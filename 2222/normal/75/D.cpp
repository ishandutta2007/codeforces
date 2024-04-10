#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    freopen("x.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<tuple<ll, ll, ll, ll>> a;
    ll s = 0, x = 0, ans = -1000000000000000000;
    for (int i = 0, l, t; i < n; ++i) {
        scanf("%d", &l);
        ll p = -ans, q = ans, r = 0, b = ans;
        for (; l --> 0; ) {
            scanf("%d", &t);
            r += t;
            b = max(b, r - p);
            p = min(p, r);
            q = max(q, r);
        }
        a.push_back(make_tuple(p, q, r, b));
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &n);
        auto t = a[n - 1];
        ans = max({ans, s + get<1>(t) - x, get<3>(t)});
        x = min(x, s + get<0>(t));
        s += get<2>(t);
    }
    printf("%lld\n", ans);
    return 0;
}