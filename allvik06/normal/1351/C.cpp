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
        string s;
        cin >> s;
        map <pair <pair <int, int>, pair <int, int>>, bool> a;
        pair <int, int> now;
        int ans = 0;
        for (char c : s) {
            pair <int, int> tm = now;
            if (c == 'N') {
                ++tm.first;
            }
            else if (c == 'S') {
                --tm.first;
            }
            else if (c == 'W') {
                --tm.second;
            }
            else if (c == 'E') {
                ++tm.second;
            }
            if (a[{now, tm}] || a[{tm, now}]) {
                ++ans;
            }
            else {
                a[{now, tm}] = true;
                ans += 5;
            }
            now = tm;
        }
        cout << ans << "\n";
    }
}