#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }
    vector<int> pmx = pref;
    for (int i = 1; i < n + 1; i++) {
        pmx[i] = max(pmx[i], pmx[i - 1]);
    }
    while (m--) {
        int x;
        cin >> x;
        if (pref[n] <= 0 && pmx.back() < x) {
            cout << -1 << ' ';
        } else if (pmx.back() >= x) {
            int pos = lower_bound(pmx.begin(), pmx.end(), x) - pmx.begin() - 1;
            cout << pos << ' ';
        } else {
            int cnt = (x - pmx.back() + pref[n] - 1) / pref[n];
            x -= cnt * pref[n];
            int pos = lower_bound(pmx.begin(), pmx.end(), x) - pmx.begin() - 1;
            pos += cnt * n;
            cout << pos << ' ';
        }
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