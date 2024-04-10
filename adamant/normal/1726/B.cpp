#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n > m) {
        cout << "No" << "\n";
    } else {
        if((n - 1) % 2 == 0) {
            cout << "Yes" << "\n";
            for(int i = 0; i < n - 1; i++) {
                cout << 1 << " ";
            }
            cout << m - (n - 1) << "\n";
        } else if((m - (n - 2)) % 2 == 0) {
            cout << "Yes" << "\n";
            for(int i = 0; i < n - 2; i++) {
                cout << 1 << " ";
            }
            int t = (m - (n - 2)) / 2;
            cout << t << ' ' << t << "\n";
        } else {
            cout << "No" << "\n";
            //assert(0);
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}