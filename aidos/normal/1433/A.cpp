#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
void solve() {
    cin >> s;
    int ans = 0;
    for(char c = '1'; c <= '9'; c++) {
        string t;
        while(t.size() < 4 && t != s) {
            t += c;
            ans += t.size();
        }
        if(t == s) break;
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}