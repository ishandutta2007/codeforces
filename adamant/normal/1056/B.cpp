#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // i * i + j * j == 0 % m?
    int ans = 0;
    for(int i = 1; i <= m && i <= n; i++) {
        for(int j = 1; j <= m && j <= n; j++) {
            int check = i * i + j * j;
            check %= m;
            if(check == 0) {
                ans += (1 + (n - i) / m) * (1 + (n - j) / m);
            }
        }
    }
    cout << ans << endl;
    return 0;
}