#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        ans += (1 << n);
        for (int i = 1; i < n / 2; i++) {
            ans += (1 << i);
        }
        for (int i = n / 2; i < n; i++) {
            ans -= (1 << i);
        }
        cout << abs(ans) << "\n";
    }
    return 0;
}