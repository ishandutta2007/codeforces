#include<bits/stdc++.h>

using namespace std;

void solve() {
    int r, g, b, ans = 0;
    cin >> r >> g >> b;
    multiset < int > t = {r, g, b};
    while ((*t.begin()) != (*t.rbegin())) {
        int x = (*t.rbegin()), y, z = (*t.begin());
        t.erase(t.find(x));
        y = (*t.rbegin());
        t.erase(t.find(y));
        t.erase(t.find(z));
        if (y == 0) {
            cout << ans << '\n';
            return;
        }
        if (y != z) {
            int cnt = y - z;
            ans += cnt;
            t.insert(z), t.insert(y - cnt), t.insert(x - cnt);
        }
        else {
            int cnt = min(x - y, 2 * y);
            if (cnt % 2 == 0) {
                ans += cnt;
                t.insert(z - cnt / 2);
                t.insert(y - cnt / 2);
                t.insert(x - cnt);
            }
            else {
                ans += cnt;
                t.insert(z - cnt / 2 - 1);
                t.insert(y - cnt / 2);
                t.insert(x - cnt);
            }
        }
    }
    int x = (*t.begin()), y = (*t.rbegin());
    if (x == y) {
        ans += (x / 2) * 3;
        if (x % 2 == 1) ans++;
    }
    cout << ans << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}