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

void solve(bool __attribute__((unused)) read) {
    int n, a, b;
    cin >> n >> a >> b;
    
    int x = -1, y = -1;
    
    for (x = 0; x <= 1e6 && n - a * x >= 0; ++x) {
        if ((n - a * x) % b == 0) {
            y = (n - a * x) / b;
            break;
        }
    }
    
    if (y == -1) {
        cout << "-1\n";
        return;
    }
    
    assert(a * x + b * y == n);
    
    vector<int> p(n);
    int cur = 0;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < a; ++j)
            p[cur + j] = cur + (j + 1) % a;
            
        cur += a;
    }
    
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < b; ++j)
            p[cur + j] = cur + (j + 1) % b;
        
        cur += b;
    }
    
    for (int i = 0; i < n; ++i)
        cout << p[i] + 1 << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}