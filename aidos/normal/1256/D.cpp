#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
ll k;
string s;
void solve() {
    cin >> n >> k >> s;
    string ans = "";
    int cnt1 = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            cnt1++;
        } else {
            while(cnt1 > k) {
                cnt1--;
                ans += '1';
            }
            k -= cnt1;
            ans += '0';
        }
    }
    while(cnt1 > 0) {
        ans += '1';
        cnt1--;
    }
    cout << ans << "\n";
}
int main() {
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}