#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m, x, y;
void solve() {
    cin >> n >> m >> x >> y;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s += "#";
        int cnt = 0;
        for(char c: s) {
            if(c == '.') cnt++;
            else {
                ans += min(cnt * x, cnt/2 * y + (cnt % 2) * x);
                cnt = 0;
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}