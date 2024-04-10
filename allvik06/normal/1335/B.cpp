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
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 0; i < n; i += b) {
            for (int j = 0; j + i < min(n, i + b); ++j) {
                cout << (char)('a' + j);
            }
        }
        cout << "\n";
    }
}