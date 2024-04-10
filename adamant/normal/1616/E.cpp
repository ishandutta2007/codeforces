#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int MOD = 998244353;
const int inf = 1e16;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    const int sigma = 26;
    vector<int> st[sigma];
    int ans = inf;
    for(int i = n - 1; i >= 0; i--) {
        st[s[i] - 'a'].push_back(i);
    }
    ordered_set moved;
    auto get = [&](int x, int i) {
        return x + moved.size() - moved.order_of_key(x) - i;
    };
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int ct = t[i] - 'a';
        for(int c = 0; c < ct; c++) {
            if(st[c].size()) {
                ans = min<int>(ans, cur + get(st[c].back(), i));
            }
        }
        if(st[ct].empty()) {
            break;
        } else {
            cur += get(st[ct].back(), i);
            moved.insert(st[ct].back());
            st[ct].pop_back();
        }
    }
    if(ans == inf) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}