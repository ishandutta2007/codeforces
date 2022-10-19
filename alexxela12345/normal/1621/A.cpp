#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2) {
        cout << -1 << endl;
        return;
    }
    vector<string> arr(n, string(n, '.'));
    for (int i = 0; i < k; i++) {
        arr[2 * i][2 * i] = 'R';
    }
    for (auto line : arr) {
        cout << line << endl;
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