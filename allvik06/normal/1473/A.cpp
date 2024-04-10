#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        int minn1 = INF, minn2 = INF, maxx = -INF;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            maxx = max(maxx, x);
            if (minn1 > x) {
                minn2 = minn1;
                minn1 = x;
            } else if (minn2 > x) {
                minn2 = x;
            }
        }
        if (minn1 + minn2 <= d || maxx <= d) cout << "Yes\n";
        else cout << "No\n";
    }
}