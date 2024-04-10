#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxn = 1e5 + 42;


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int a = abs(x - y) * t1;
    int b = 3 * t3 + (abs(x - z) + abs(x - y)) * t2;
    cout << (b <= a ? "YES" : "NO") << endl;
    return 0;
}