#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

bool check(int n) {
    if (n == 1) {
        return false;
    }
    int cur = 2;
    while (cur * cur <= n) {
        if (n % cur == 0) {
            return false;
        }
        cur++;
    }
    return true;
}

void solve() {
    int n, e;
    cin >> n >> e;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    for (int i = 0; i < e && i < n; i++) {
        vector<int> a;
        for (int j = i; j < n; j += e) {
            a.push_back(arr[j]);
        }
        for (int j = 0; j < (int) a.size(); j++) {
            if (check(a[j])) {
                int l = j;
                while (l > 0 && a[l - 1] == 1)
                    l--;
                int r = j;
                while (r + 1 < (int) a.size() && a[r + 1] == 1)
                    r++;
                ans += (ll) (j - l + 1) * (r - j + 1) - 1;
            }
        }
    }
    cout << ans << endl;
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