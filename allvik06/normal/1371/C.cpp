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
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        int kol = min(m, min(a, b));
        m -= kol;
        if (a < b) a -= kol;
        else b -= kol;
        if (a + b >= n && m == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}