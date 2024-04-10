#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool /*read*/) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int min_ops = 1e9;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int n_ops = 0;
        for (int j = i + 1; j < n; j++) {
            if (x == 1) break;
            x = __gcd(x, a[j]);
            n_ops++;
        }
        
        if (x == 1) {
            min_ops = min(min_ops, n_ops);
        }
        
        x = a[i];
        n_ops = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (x == 1) break;
            x = __gcd(x, a[j]);
            n_ops++;
        }
        
        if (x == 1) {
            min_ops = min(min_ops, n_ops);
        }
    }
    
    if (min_ops >= 1e9) {
        cout << "-1\n";
        return;
    }
    
    int have_ones = count(all(a), 1);
    
    if (have_ones > 0) {
        cout << n - have_ones << "\n";
    }
    else {
        assert(min_ops > 0);
        cout << n + min_ops - 1 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}