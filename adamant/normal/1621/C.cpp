#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int inf = 1e9;
const int maxn = 1e5 + 42;

int ask(int x) {
    cout << "? " << x + 1 << endl;
    int t;
    cin >> t;
    return t - 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if(!ans[i]) {
            int j = ask(i);
            while(!ans[j]) {
                int tj = ask(i);
                ans[j] = tj + 1;
                j = tj;
            }
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
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