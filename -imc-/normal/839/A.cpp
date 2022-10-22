#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

using li = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int sum = 0, cansum = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        int can = min(sum, 8);
        sum -= can;
        cansum += can;
        
        if (cansum >= k) {
            cout << (i + 1) << endl;
            return;
        }
    }
    
    cout << "-1\n";
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve();
    
    return 0;
}