#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    string s[n];
    unordered_set<string> pr = {""};
    bool ans = false;
    for(auto &it: s) {
        cin >> it;
        pr.insert(it);
        string t = it;
        reverse(all(t));
        ans |= pr.count(t) || pr.count(t.substr(0, t.size() - 1));
        for(char c = 'a'; c <= 'z'; c++) {
            ans |= pr.count(t + c);
        }
    }
    cout << (ans ? "YES" : "NO") << "\n";
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
}