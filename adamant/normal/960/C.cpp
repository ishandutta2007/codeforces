#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, d;
    cin >> x >> d;
    const int logn = 30;
    vector<int> ans;
    int cur = 1;
    for(int i = logn; i > 0; i--) {
        while((1LL << i) - 1 <= x) {
            for(int j = 0; j < i; j++) {
                ans.push_back(cur);
            }
            x -= (1 << i) - 1;
            cur += d + 1;
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << ' ';
    }
    return 0;
}