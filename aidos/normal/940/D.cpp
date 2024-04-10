#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
string s;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;
    int l = -1e9, r = 1e9;
    for(int i = 4; i < n; i++) {
        if(s[i] != s[i-1]) {
            if(s[i] == '1') {
                for(int j = 0; j <= 4; j++) {
                    l = max(l, a[i-j] + 1);
                }
            } else {
                for(int j = 0; j <= 4; j++) {
                    r = min(r, a[i-j] - 1);
                }
            }
        }
    }
    cout << l << " "<< r << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}