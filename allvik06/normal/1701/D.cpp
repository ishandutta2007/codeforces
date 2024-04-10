#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> b[i];
    vector <int> mn(n + 1), mx(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0) {
            mn[i] = i + 1;
            mx[i] = n;
            continue;
        }
        mx[i] = i / b[i];
        mn[i] = i / (b[i] + 1) + 1;
    }
    vector <vector <int>> add(n + 1);
    for (int i = 1; i <= n; ++i) {
        add[mx[i]].push_back(i);
    }
    set <pair <int, int>> s;
    vector <int> p(n + 1);
    for (int i = n; i >= 1; --i) {
        for (int j : add[i]) {
            s.insert(make_pair(-mn[j], j));
        }
        p[s.begin()->second] = i;
        s.erase(s.begin());
    }
    for (int i = 1; i <= n; ++i) cout << p[i] << " ";
    cout << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */