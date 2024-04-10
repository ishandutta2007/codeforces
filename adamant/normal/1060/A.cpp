#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt8 = count(all(s), '8');
    int ans = 0;
    for(int i = 1; i <= cnt8; i++) {
        if((n - i) / 10 >= i) {
            ans = i;
        }
    }
    cout << ans << endl;
}