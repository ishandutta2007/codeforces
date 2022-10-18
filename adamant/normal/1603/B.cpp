#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

int ans(int x, int y) {
    if(x > y) {
        return x + y;
    } else {
        return (y + (y / x) * x) / 2;
    }
}

void solve() {
    int x, y;
    cin >> x >> y;
    int n = ans(x, y);
    cout << n << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}