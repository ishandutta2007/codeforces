#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define int int64_t

const int maxn = 1e5 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string need = s;
    sort(all(need));
    int n = s.size();
    int ans[n];
    for(int i = 1; i <= n; i++) {
        if(s[n - i] != need[n - i]) {
            ans[n - i] = 1;
            reverse(begin(need), end(need) - i + 1);
        } else {
            ans[n - i] = 0;
        }
    }
    for(auto it: ans) {
        cout << it << ' ';
    }
    return 0;
}