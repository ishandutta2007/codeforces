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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxp[n + 2][2], maxs[n + 2][2];
    memset(maxp, 0, sizeof(maxp));
    memset(maxs, 0, sizeof(maxs));
    for(int i = 1; i <= n; i++) {
        maxp[i][0] = maxp[i - 1][0] + (a[i - 1] == 1);
        maxp[i][1] = max(maxp[i - 1][0], maxp[i - 1][1]) + (a[i - 1] == 2);
    }
    for(int i = n; i >= 1; i--) {
        maxs[i][1] = maxs[i + 1][1] + (a[i - 1] == 2);
        maxs[i][0] = max(maxs[i + 1][0], maxs[i + 1][1]) + (a[i - 1] == 1);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int cur[2][2];
        memset(cur, 0, sizeof(cur));
        for(int j = i; j >= 1; j--) {
            int ncur[2][2];
            ncur[0][0] = cur[0][0] + (a[j - 1] == 1);
            ncur[1][1] = cur[1][1] + (a[j - 1] == 2);
            ncur[0][1] = max(cur[0][0], cur[0][1]) + (a[j - 1] == 2);
            cur[0][0] = ncur[0][0];
            cur[1][1] = ncur[1][1];
            cur[0][1] = ncur[0][1];
            ans = max({ans, maxp[j - 1][0] + cur[0][0] + maxs[i + 1][0],
                            maxp[j - 1][0] + cur[0][1] + maxs[i + 1][1],
                            maxp[j - 1][1] + cur[1][1] + maxs[i + 1][1]});
        }
    }
    cout << ans << endl;
    return 0;
}