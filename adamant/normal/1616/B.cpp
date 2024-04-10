#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    int ctr = 0;
    for(auto it: s) {
        // s_{k-1} < s_k -> always better to add
        if(t == "" || it < t.back()) {
            ctr += t != "" && it < t.back();
            t += it;
        } else if(it == t.back() && ctr > 0) { // ccbb -> cc, but cbbb -> cbbbbc
            t += it;
        } else {
            break;
        }
    }
    cout << t + string(t.rbegin(), t.rend()) << "\n";
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