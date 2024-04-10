#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int ans = 1;
        int maxx = -1e9, minn = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            maxx = max(maxx, arr[i]);
            minn = min(minn, arr[i]);
        }
        bool good = true;
        for (int i = 0; i < n; i++) {
            ans = ans * (arr[i] / __gcd(arr[i], ans));
            if (ans > maxx * minn) {
                good = false;
            }
        }
        if (good) {
        sort(arr.begin(), arr.end());
        if (find(arr.begin(), arr.end(), ans) != arr.end()) {
            ans *= arr[0];
        }
        vector<int> kek;
        int i;
        for (i = 2; i * i <= ans; i++) {
            if (ans % i == 0) {
                kek.push_back(i);
                if (i * i != ans) {
                    kek.push_back(ans / i);
                }
            }
        }
        sort(kek.begin(), kek.end());
        if (kek == arr)
        cout << ans << endl;
        else
            cout << -1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}