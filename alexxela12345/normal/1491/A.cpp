#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> arr(n);
    vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            x--;
            cnt[arr[x]]--;
            arr[x] ^= 1;
            cnt[arr[x]]++;
        } else {
            if (cnt[1] >= x) {
                cout << 1;
            } else {
                cout << 0;
            }
            cout << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}