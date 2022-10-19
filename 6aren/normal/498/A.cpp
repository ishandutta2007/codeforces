#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int u = x * a + y * b + c;
        int v = xx * a + yy * b + c;
        u /= abs(u);
        v /= abs(v);
        if (u != v) ans++;
    }
    cout << ans;
    return 0;
}