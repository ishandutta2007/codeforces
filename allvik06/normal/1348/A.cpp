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
        int n;
        cin >> n;
        int now = 0;
        now += (1 << n);
        for (int i = 1; i < n / 2; ++i) {
            now += (1 << i);
        }
        for (int i = n / 2; i < n; ++i) {
            now -= (1 << i);
        }
        cout << now << "\n";
    }
}