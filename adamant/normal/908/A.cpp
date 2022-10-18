#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for(auto c: s) {
        ans += c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == '1' || c == '3' || c == '5' || c == '7' || c == '9';
    }
    cout << ans << endl;
    return 0;
}