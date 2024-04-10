#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read) {
    int n;
    cin >> n;
    
    int s = sqrt(n);
    
    int can = 2 * n + 2;
    for (int x = max(s - 100, 1); x <= min(x + 100, n); x++)
        for (int y = max(s - 100, 1); y <= min(s + 100, n); y++) {
            li area = x * (li)y;
            if (area < n) continue;
            
            can = min(can, 2 * (x + y));
        }
        
    cout << can << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}