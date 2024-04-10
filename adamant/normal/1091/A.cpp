#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int y, b, r;
    cin >> y >> b >> r;
    int ans = 0;
    for(int R = 3; R <= r; R++) {
        if(R - 1 <= b && R - 2 <= y) {
            ans = max(ans, R + (R - 1) + (R - 2));
        }
    }
    cout << ans << endl;
    return 0;
}