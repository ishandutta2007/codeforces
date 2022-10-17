#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
            queries[i].first--;
            queries[i].second--;
        }
        if (n == 1) {
            for (int i = 0; i <= q; i++) {
                cout << 1 << '\n';
            }
            continue;
        }
        auto up = [&](int id) -> bool {
            bool b1 = (id == n - 1 ? true : (a[id] > a[id + 1]));
            bool b2 = (id == 0 ? true : a[id] > a[id - 1]);
            return b1 && b2;
        };
        auto down = [&](int id) -> bool {
            bool b1 = (id == n - 1 ? true : (a[id] < a[id + 1]));
            bool b2 = (id == 0 ? true : a[id] < a[id - 1]);
            return b1 && b2;
        };
        auto value = [&](int id) -> int {
            if (id == 0 || id == n - 1) {
                if (down(id)) return 0;
                return a[id];
            } else {
                if (up(id)) {
                    return a[id];
                } else if (down(id)){
                    return -a[id];
                }
            }
            return 0;
        };
        auto valid = [&](int id) -> bool {
            return id >= 0 && id < n;
        };
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += value(i);
        }
        cout << ans << '\n';
        for (auto qq: queries) {
            set<int> use;
            int l = qq.first;
            int r = qq.second;
            for (int d = -1; d <= 1; d++) {
                use.insert(l + d);
                use.insert(r + d);
            }
            for (int x: use) {
                if (valid(x)) {
                    ans -= value(x);
                }
            }
            swap(a[l], a[r]);
            for (int x: use) {
                if (valid(x)) {
                    ans += value(x);
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}