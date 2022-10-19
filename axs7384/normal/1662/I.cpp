#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 9;
const long long inf = 1e10;

long long a[N], x[N];


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%lld", x + i);
        x[i] *= 2;
    }
    x[++m] = -inf; x[++m] = inf;
    sort(x + 1, x + m + 1);
    vector<pair<long long, int>> vc;
    for (int i = 1; i <= n; ++i) {
        long long r = *lower_bound(x + 1, x + m + 1, (i - 1) * 200);
        long long l = *(upper_bound(x + 1, x + m + 1, (i - 1) * 200) - 1);
        long long L = max(l + 1, (i - 1) * 400 - r + 1);
        long long R = min(r - 1, (i - 1) * 400 - l - 1);
        if (L > R) continue;
        vc.push_back({L, a[i]});
        vc.push_back({R + 1, -a[i]});
    }
    sort(vc.begin(), vc.end());
    long long maxv = 0, sum = 0;
    for (int i = 0, sz = vc.size(); i < sz; ++i) {
        sum += vc[i].second;
        if (i == sz - 1 || vc[i].first != vc[i + 1].first) {
            maxv = max(maxv, sum);
        }        
    }
    printf("%lld\n", maxv);
    return 0;
}

/*
3 1
2 5 6
169
-10000000000 338 -337 337
-10000000000 338 63 337
338 10000000000 339 461
2
*/