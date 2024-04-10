#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
string s, t;
void solve() {
    cin >> n >> s >> t;
    vector<int> a;
    int cnt0 = 0, cnt1 = 0, cnt = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == t[i]) continue;
        if(s[i] == '0') {
            a.emplace_back(1);
            if(cnt0) {
                cnt0--;
            } else {
                ans++;
            }
            cnt1++;
            cnt++;
        }
        else {
            a.emplace_back(0);
            if(cnt1) {
                cnt1--;
            } else {
                ans++;
            }
            cnt0++;
            cnt--;
        }
        ans = max(ans, abs(cnt));
    }
    if(cnt != 0) {
        cout << -1 << "\n";
        return;
    }
    cout << ans << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}