#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1000;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> ans;
    vector<int> ones, twos;
    for(int i = n; i >= 1; i--) {
        if(a[i] == 0) {
            continue;
        } else if(a[i] == 1) {
            ans.emplace_back(i, i);
            ones.push_back(i);
        } else if(a[i] == 2) {
            if(!ones.empty()) {
                ans.emplace_back(ones.back(), i);
                ones.pop_back();
                twos.push_back(i);
            } else {
                cout << -1 << endl;
                return;
            }
        } else { // a[i] == 3
            if(!twos.empty()) {
                ans.emplace_back(i, i);
                ans.emplace_back(i, twos.back());
                twos.back() = i;
            } else if(!ones.empty()) {
                ans.emplace_back(i, i);
                ans.emplace_back(i, ones.back());
                ones.pop_back();
                twos.push_back(i);
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it.first << ' ' << it.second << endl;
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