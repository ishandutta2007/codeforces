#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 14;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        vector<int> b(a, a + n);
        int t = a[i];
        b[i] = 0;
        for(int j = 1; j <= n; j++) {
            b[(i + j) % n] += (t / n) + (j <= t % n);
        }
        int cur = 0; 
        for(int i = 0; i < n; i++) {
            cur += (!(b[i] % 2)) * b[i];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}