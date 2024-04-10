#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
    int n;
    ld r;
    cin >> n >> r;
    
    vector<ld> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        
        ld& cur_y = y[i];
        cur_y = r;
        
        for (int j = 0; j < i; j++) {
            ld dx = abs(x[i] - x[j]);
            if (dx <= 2 * r + 1e-5) {
                cur_y = max(cur_y, y[j] + sqrt(max(4 * r * r - dx * dx, (ld)0)));
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(12) << y[i] << " ";
    }
    cout << "\n";
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