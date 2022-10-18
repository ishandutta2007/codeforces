#include <bits/stdc++.h>

using namespace std;

//#define int int64_t
const int maxn = 1e6 + 42;

int mx[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[m], d[m];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    vector<pair<int, int>> res;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] <= c[j] && b[i] <= d[j]) {
                int dx = c[j] - a[i];
                int dy = d[j] - b[i] + 1;
                mx[dx] = max(mx[dx], dy);
            }
        }
    }
    int ans = 1e9;
    for(int i = maxn - 2; i >= 0; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
        ans = min(ans, i + mx[i]);
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}