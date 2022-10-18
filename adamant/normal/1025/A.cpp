#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for(auto c: s) {
        cnt[c]++;
    }
    int ans = 0;
    for(auto it: cnt) {
        ans += it.second > 1;
    }
    cout << ((ans > 0 || cnt.size() == 1) ? "Yes" : "No") << endl;
    return 0;
}