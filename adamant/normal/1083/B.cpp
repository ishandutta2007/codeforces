#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    int pos = 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(pos == 1) {
            pos = b[i] - a[i] + 1;
        } else {
            pos = (pos - 2) * 2 + ('b' - a[i] + 1) + (b[i] - 'a' + 1);
        }
        pos = min(pos, (int)1e9);
        ans += min(pos, k);
    }
    cout << ans << endl;
    return 0;
}