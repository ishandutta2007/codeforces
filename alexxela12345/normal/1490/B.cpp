#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> c(3);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            c[arr[i] % 3]++;
        }
        int ans = 0;
        while (*min_element(c.begin(), c.end()) < *max_element(c.begin(), c.end())) {
            int  mn = max_element(c.begin(), c.end()) - c.begin();
            c[mn] -= 1;
            c[(mn + 1) % 3]++;
            ans++;
        }
        cout << ans << endl;
    }
}