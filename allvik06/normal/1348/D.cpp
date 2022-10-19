#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> ans(60);
        int now = 1, pr = 1, len = 0;
        for (int i = 0; i < 60; ++i) {
            if (now == n) {
                len = i - 1;
                break;
            }
            if (now + pr == n) {
                len = i;
                break;
            }
            if (now + pr > n) {
                now -= pr;
                pr /= 2;
                int h = n - now;
                --i;
                if (h > 2 * pr) {
                    ans[i] = h / 2 - pr;
                    len = i + 1;
                    if (h % 2 != 0) {
                        ans[i + 1] = 1;
                    } else {
                        ans[i + 1] = 0;
                    }
                }
                else {
                    ans[i] = h - pr;
                    len = i;
                }
                break;
            }
            else {
                ans[i] = pr;
                pr *= 2;
                now += pr;
            }
        }
        cout << len + 1 << "\n";
        for (int i = 0; i <= len; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}