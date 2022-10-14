#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    const ull mod = 1ull << 32;
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll l, r;
        ull x, y, z, b1, b2;
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
        r -= l - 1;
        ull b[n];
        b[0] = b1, b[1] = b2;
        ll a[n];
        for (int i = 2; i < n; ++i)
            b[i] = (b[i - 2] * x % mod + b[i - 1] * y % mod + z) % mod;
        for (int i = 0; i < n; ++i) a[i] = b[i] % r + l;
        int n1 = 0;
        while (n1 < n && a[n1] >= 0) ++n1;
        int n2 = n1;
        while (n2 < n && a[n2] <= 0) ++n2;
        ll ans = 4e18, mn;
        bool find = false;
        if (n2 < n) {
            find = true;
            mn = a[n1];
            for (int i = n1 + 1; i < n2; ++i) mn = min(mn, a[i]);
            for (int i = n2; i < n; ++i) {
                if (mn < a[i]) ans = min(ans, mn * a[i]);
                else mn = a[i];
            }
        }
        else {
            mn = a[0];
            for (int i = 1; i < n1; ++i) {
                if (mn < a[i]) ans = min(ans, mn * a[i]), find = true;
                else mn = a[i];
            }
            mn = -a[n - 1];
            for (int i = n - 2; i >= n1; --i) {
                a[i] *= -1;
                if (mn < a[i]) ans = min(ans, mn * a[i]), find = true;
                else mn = a[i];
            }
        }
        if (find) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}