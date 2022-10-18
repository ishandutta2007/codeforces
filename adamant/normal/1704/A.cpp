#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    for(int i = 0; i < m - 1; i++) {
        if(b[i] != a[i]) {
            cout << "NO\n";
            return;
        }
    }
    for(int i = m - 1; i < n; i++) {
        if(a[i] == b[m - 1]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}