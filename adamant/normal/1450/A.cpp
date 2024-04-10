#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 2e5 + 42;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(all(s));
    cout << s << endl;
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