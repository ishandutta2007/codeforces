#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

bool is_pal(string s) {
    return s == string(s.rbegin(), s.rend());
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], x[n];
    map<int, int> lol;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> x[i];
        lol[a[i]] = x[i];
    }
    int m;
    cin >> m;
    int b[m], y[m];
    for(int i = 0; i < m; i++) {
        cin >> b[i] >> y[i];
        lol[b[i]] = max(lol[b[i]], y[i]);
    }
    int ans = 0;
    for(auto it: lol) {
        ans += it.second;
    }
    cout << ans << endl;
    return 0;
}