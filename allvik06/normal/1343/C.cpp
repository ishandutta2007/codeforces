#include <bits/stdc++.h>

using namespace std;
#define int long long


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxx = -1, now = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (i == 0) {
                if (tmp < 0) {
                    now = -1;
                }
                else {
                    now = 1;
                }
                maxx = tmp;
            }
            else {
                if (tmp < 0) {
                    if (now == -1) {
                        maxx = max(maxx, tmp);
                    }
                    else {
                        ans += maxx;
                        maxx = tmp;
                        now = -1;
                    }
                }
                else {
                    if (now == 1) {
                        maxx = max(maxx, tmp);
                    }
                    else {
                        ans += maxx;
                        maxx = tmp;
                        now = 1;
                    }
                }
            }
        }
        ans += maxx;
        cout << ans << "\n";
    }
}