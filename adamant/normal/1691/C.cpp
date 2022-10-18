#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    for(int i = 0; i + 1 < n; i++) {
        ans += stol(s.substr(i, 2));
    }
    int cnt = count(begin(s), end(s), '1');
    if(cnt == 0) {
        cout << ans << "\n";
    } else {
        int L = 0;
        int R = 0;
        while(s[L] != '1') {
            L++;
        }
        while(s[n - R - 1] != '1') {
            R++;
        }
        if(L && R && L + R <= k && cnt > 1) {
            cout << ans - 11 << "\n";
        } else if(R && R <= k) {
            cout << ans - 10 + !(L || cnt > 1) << "\n"; // x10 -> x01
        } else if(L && L <= k && (R || cnt > 1)) {
            cout << ans - 1 << "\n"; // 01x -> 10x
        } else {
            cout << ans << "\n";
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 10000;
    cin >> t;
    while(t--) {
        solve();
    }
    cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << endl;
}