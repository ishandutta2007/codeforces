#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int l = -1;
    int r = n - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cur = 0;
        for (int i = 0; i <= m; i++) {
            cur += arr[i].first;
        }
        bool good = 1;
        for (int j = m + 1; j < n; j++) {
            if (cur < arr[j].first) {
                good = 0;
                break;
            }
            cur += arr[j].first;
        }
        if (good) {
            r = m;
        } else {
            l = m;
        }
    }
    vector<int> ans;
    for (int i = r; i < n; i++) {
        ans.push_back(arr[i].second + 1);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int el : ans) {
        cout << el << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}