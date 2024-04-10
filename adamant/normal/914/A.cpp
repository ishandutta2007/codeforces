#include <bits/stdc++.h> 

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int ans = -1e7;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) {
            ans = max(ans, a[i]);
            continue;
        }
        int sq = llround(sqrt(a[i]));
        if(sq * sq != a[i]) {
            ans = max(ans, a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}