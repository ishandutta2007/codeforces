#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i && arr[i] == arr[i - 1]) {
            cnt++;
        }
    }
    if (!cnt) {
        cout << 0 << "\n";;
        return;
    }
    int first = -1;
    int last = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (arr[i] == arr[i + 1]) {
            last = i;
            if (first == -1) {
                first = i;
            }
        }
    }
    int len = last - first;
    if (len == 0) {
        cout << "0\n";
    } else if (len == 1) {
        cout << "1\n";
    } else {
        cout << last - first - 1 << "\n";
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