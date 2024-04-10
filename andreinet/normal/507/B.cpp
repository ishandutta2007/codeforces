#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long i64;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    i64 r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;

    double dist = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
    i64 ans = i64(dist / (2 * r));
    if ((2 * r) * ans + 1e-10 < dist) ++ans;

    cout << ans << '\n';
}