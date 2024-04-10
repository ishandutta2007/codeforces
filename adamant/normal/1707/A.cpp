#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n];
    int t = q;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > t) {
            t--;
        }
    }
    if(t >= 0) {
        cout << string(n, '1') << "\n";
        return;
    }
    reverse(a, a + n);
    string s(n, '0');
    t = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= t + 1 && t < q) {
            t++;
            s[n - i - 1] = '1';
        } else if(a[i] <= t) {
            s[n - i - 1] = '1';
        }
    }
    cout << s << "\n";
}
 
signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}