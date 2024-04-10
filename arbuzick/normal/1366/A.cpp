#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int ans = min(a, b - a);
        a -= ans;
        b -= ans * 2;
        if (a != 0) {
            ans += a / 3 * 2;
            a = a % 3;
            ans += a / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}