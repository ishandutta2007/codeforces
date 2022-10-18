#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, r, x;
    cin >> n >> r;
    multiset < int > a;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a.insert(x);
    }
    int ans = 0;
    while ((int)a.size() > 0) {
        while ((int)a.size() > 0 && (*a.rbegin()) - ans * r <= 0) {
            int y = (*a.rbegin());
            a.erase(a.find(y));
        }
        if ((int)a.size() == 0) break;
        ans++;
        int x = (*a.rbegin());
        a.erase(a.find(x));
        while ((int)a.size() > 0 && (*a.rbegin()) == x) {
            a.erase(a.find(x));
        }
    }
    cout << ans << '\n';
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}