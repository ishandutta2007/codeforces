#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int l[n], r[n];
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    sort(l, l + n);
    sort(r, r + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(l[i], r[i]);
    }
    cout << ans + n << endl;
}