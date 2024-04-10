#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    int sm = 0;
    for  (int i = 0; i < n; i++) {
        cin >> arr[i];
        sm += arr[i];
    }
    if (sm == x) {
        cout << "NO" << endl;
        return;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + arr[i] == x) {
            swap(arr[i], arr[i + 1]);
        }
        cur += arr[i];
        assert(cur != x);
    }
    cout << "YES" << endl;
    for (int el : arr) {
        cout << el << " ";
    }
    cout << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}