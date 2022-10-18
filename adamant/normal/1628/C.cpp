#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int z = 0; 2 * z < n; z += 2) {
        int m = n - 2 * z;
        auto get = [&](int i) {
            if(i < m - 1) {
                return a[z + i][z];
            }
            i -= m - 1;
            if(i < m - 1) {
                return a[z + m - 1][z + i];
            }
            i -= m - 1;
            if(i < m - 1) {
                return a[z + m - 1 - i][z + m - 1];
            }
            i -= m - 1;
            return a[z][z + m - 1 - i];
        };
        for(int i = 0; i < 4 * (m - 1); i += 4) {
            ans ^= get(i) ^ get(i + 1);
        }
    }
    cout << ans << "\n";
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
}