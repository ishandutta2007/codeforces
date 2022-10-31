#include<bits/stdc++.h>

using namespace std;

#define int long long

inline int get(int x) {
    return x * (x - 1) / 2 + 2 * x * (2 * x + 1) / 2 - x * x;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        int start = sqrtl(n) + 100;
        while (n > 1) {
            ans++;
            while (1) {
                if (get(start) <= n) {
                    n -= get(start);
                    break;
                }
                start--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}