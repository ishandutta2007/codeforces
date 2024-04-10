#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

void solve(bool read) {
    int n;
    li L;
    cin >> n >> L;
    vector<li> c(31);
    for (int i = 0; i < 31; i++) {
        if (i < n)
            cin >> c[i];
        else
            c[i] = 2 * c[i - 1];
        
        if (i != 0)
            c[i] = min(c[i], 2 * c[i - 1]);
    }
    
    li ans = 0;
    li can = numeric_limits<li>::max();
    for (int i = 30; i >= 0; i--) {
        if (L & (1LL << i)) {
            ans += c[i];
        }
        
        can = min(can, ans + c[i]);
    }
    can = min(can, ans);
        
    cout << can << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //solve(false);
    
    return 0;
}