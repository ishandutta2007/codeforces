#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int f = a, s = 2 * b, ff = b, ss = 2 * a;
        cout << min(max(f, s) * max(f, s), max(ff, ss) * max(ff, ss)) << "\n";
    }
}