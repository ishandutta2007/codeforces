#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e15;


signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        if (r1 >= r2) {
            int now = n * (r2 - l2);
            int len = l2 - l1 + r1 - r2;
            if (now >= k) cout << 0 << "\n";
            else if (now + len * n >= k) cout << k - now << "\n";
            else cout << len * n + (k - now - len * n) * 2 << "\n";
        }
        else if (r1 <= r2 && r1 >= l2) {
            int now = n * (r1 - l2);
            int len = l2 - l1 + r2 - r1;
            if (now >= k) cout << 0 << "\n";
            else if (now + len * n >= k) cout << k - now << "\n";
            else cout << len * n + (k - now - len * n) * 2 << "\n";
        }
        else {
            int minn = INF;
            for (int i = 1; i <= n; ++i) {
                int now = (l2 - r1) * i;
                int len = r2 - l1;
                if (len * i >= k) minn = min(minn, now + k);
                else minn = min(minn, now + len * i + 2 * (k - len * i));
            }
            cout << minn << "\n";
        }
    }
}