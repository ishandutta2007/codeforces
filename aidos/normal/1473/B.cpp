#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500;
const ll inf = (1ll<<50);
int n, d;
void solve() {
    string s, t;
    cin >> s >> t;
    string ans = "";
    while(ans.size() < 500) {
        ans += s;
        if(ans.size() % t.size() != 0) continue;
        int ok = 1;
        for(int i = 0; i < ans.size(); i++) {
            if(t[i % t.size()] != ans[i]) ok = 0;
        }
        if(ok) {
            cout << ans << "\n";
            return;
        }
    }
    cout << "-1\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}