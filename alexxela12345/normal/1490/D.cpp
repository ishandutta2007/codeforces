#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> arr, ans;

void kek(int l, int r, int d) {
    if (l == r) {
        return;
    }
    if (l + 1 == r) {
        ans[l] = d;
        return;
    }
    int pos = max_element(arr.begin() + l, arr.begin() + r) - arr.begin();
    ans[pos] = d;
    kek(l, pos, d + 1);
    kek(pos + 1, r, d + 1);
}

void solve() {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ans.assign(n, 0);
    kek(0, n, 0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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