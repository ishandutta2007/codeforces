#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1e6 + 42;

void solve() {
    int l, r;
    cin >> l >> r;
    vector<tuple<int, int, int>> ans;
    int start = 0, finish = 31;
    if(l > 1) {
        ans.emplace_back(0, 1, l - 1);
        r -= l - 1;
        l -= l - 1;
        start = 1;
    }
    for(int i = 1; i < 22; i++) {
        for(int j = 0; j < i; j++) {
            ans.emplace_back(finish - i, finish - j, 1 << max((int)0, j - 1));
        }
    }
    for(int i = 22; i > 0; i--) {
        int P = 1 << (i - 1);
        if(r > P) {
            ans.emplace_back(start, finish - i, r - P);
            r -= P;
        }
    }
    if(r) {
        assert(r == 1);
        ans.emplace_back(start, finish, 1);
    }
    cout << "YES" << endl;
    cout << finish + 1 << ' ' << ans.size() << endl;
    for(auto it: ans) {
        int a, b, c;
        tie(a, b, c) = it;
        cout << a + 1 << ' ' << b + 1 << ' ' << c << "\n";
    }
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