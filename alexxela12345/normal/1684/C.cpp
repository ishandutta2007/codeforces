#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m));
    int i1 = -1, i2 = -1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
        auto brr = arr[i];
        sort(brr.begin(), brr.end());
        if (brr == arr[i])
            continue;
        vector<int> inds;
        for (int j = 0; j < m; j++) {
            if (brr[j] != arr[i][j]) {
                inds.push_back(j);
            }
        }
        i1 = inds[0];
        i2 = inds[1];
    }
    if (i1 == -1) {
        cout << "1 1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        swap(arr[i][i2], arr[i][i1]);
    }
    for (auto &el : arr) {
        if (!is_sorted(el.begin(), el.end())) {
            cout << "-1\n";
            return;
        }
    }
    cout << i1 + 1 << " " << i2 + 1 << "\n";
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