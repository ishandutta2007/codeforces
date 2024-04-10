#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)1000200;
const ll inf = (1ll<<50);
int n;
string s;
void solve() {
    cin >> n >> s;
    int ans = n + 1;
    for(int i = 0; i <= n/2; i++) {
        for(int j = 0; j <= n/2; j++) {
            string t;
            for(int d = 1; d <= i; d++) t += "(";
            int k1 = n/2-i;
            int k2 = j;
            for(auto x: s) {
                if(x == '(') {
                    if(k1 > 0) {
                        t += "(";
                        k1--;
                    }
                } else {
                    if(k2 == 0) t += ")";
                    else k2--;
                }
            }
            for(int d = 1; d <= j; d++) t += ")";
            int bal = 0;
            int ok = 1;
            for(auto x: t) {
                if(x == ')') bal--;
                else bal++;
                if(bal < 0) ok = 0;
            }

            if(ok) {
                //cout << t << "\n";
                ans = min(ans, i + j);
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}