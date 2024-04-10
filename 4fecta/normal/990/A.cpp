#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a, b;
int32_t main() {
    cin >> n >> m >> a >> b;
    int lo = n / m * m;
    int hi = lo + m;
    int ans = min((n - lo) * b, (hi - n) * a);
    printf("%lld\n", ans);
}