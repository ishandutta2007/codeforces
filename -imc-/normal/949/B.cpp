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
    li n;
    int q;
    cin >> n >> q;
    
    for (int i = 0; i < q; ++i) {
        li x;
        cin >> x;
        
        li after = n - x + (x - 1) / 2;
        
        // numbers before x
        //li before = x - 1;
        
        li pos = x;
        
        while (pos % 2 != 1) {
            //cout << "pos " << pos << " after " << after << endl;
            pos += after + 1;
            after /= 2;
            //cout << "pos " << pos << " after " << after << endl;
            
            //before -= after + 1;
            //after += after;
            //pos -= after + 1;
        }
        
        //cout << "raw " << pos << "\n";
        cout << (pos + 1) / 2 << "\n";
    }
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