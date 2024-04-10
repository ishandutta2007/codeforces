#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> divs;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.insert(i);
            divs.insert(n / i);
        }
    }
    set<int> ans;
    for(auto it: divs) {
        int k = n / it;
        ans.insert(k + k * (n - it) / 2); // it + 2 * it + ... + (n / it) * it
    }
    for(auto it: ans) {
        cout << it << ' ';
    }
    return 0;
}