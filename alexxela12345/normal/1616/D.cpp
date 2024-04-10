#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    for (auto &el : arr) {
        el -= x;
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + arr[i];
    }
    vector<pair<int, int>> segs;
    set<pair<int, int>> s;
    for (int i = 2; i <= n; i++) {
        s.insert({pref[i - 2], i - 2});
        while (!s.empty() && s.rbegin()->first > pref[i]) {
            segs.push_back({s.rbegin()->second, i});
            s.erase(--s.end());
        }
    }
    sort(segs.begin(), segs.end(), [&](auto a, auto b) { return a.second < b.second; });
    int last = -1;
    int cnt = 0;
    for (auto &el : segs) {
        int l = el.first;
        int r = el.second;
        if (last < l) {
            cnt++;
            last = r - 1;
        }
    }
    cout << n - cnt << endl;
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