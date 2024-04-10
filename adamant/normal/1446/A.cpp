#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n, W;
    cin >> n >> W;
    int w[n];
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int a, int b){return w[a] > w[b];});
    vector<int> ans;
    int C = 0;
    for(int i = 0; i < n; i++) {
        if(w[p[i]] + C <= W) {
            ans.push_back(p[i]);
            C += w[p[i]];
        }
    }
    if(2 * C >= W) {
        cout << ans.size() << "\n";
        for(auto it: ans) {
            cout << it + 1 << ' ';
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}