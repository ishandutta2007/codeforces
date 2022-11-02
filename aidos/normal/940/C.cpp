#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n, k;
string s;
int a[26];
void solve() {
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++) a[s[i] - 'a'] = 1;
    string ans;
    int mi = 0;
    while(a[mi] == 0) ++mi;
    int mx = 25;
    while(a[mx] == 0) --mx;
    if(k > n) {
        ans = s;
    } else {
        int pos = k-1;
        while(s[pos] == mx + 'a') pos--;
        for(int i = 0; i < pos; i++) {
            ans += s[i];
        }
        int val = s[pos] - 'a'+1;
        while(a[val] == 0) ++val;
        ans += char(val + 'a');
    }
    while (ans.size() < k) ans += char(mi + 'a');
    cout << ans << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}