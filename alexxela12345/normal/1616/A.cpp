#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    while (n--) {
        int x;
        cin >> x;
        x = abs(x);
        cnt[x]++;
    }
    int ans = 0;
    for (auto el : cnt) {
        int k = 2;
        if (el.first == 0)
            k = 1;
        ans += min(k, el.second);
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