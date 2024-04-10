#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define all(v) (v).begin(),(v).end()

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = accumulate(all(arr), 0);
    if (sum % n == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}