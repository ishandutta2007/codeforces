#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
    int n, k;
    cin >> n >> k;
    
    vector<int> have(16);
    for (int i = 0; i < n; i++) {
        int m = 0;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (x)
                m |= (1 << j);
        }
        have[m]++;
    }
    
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            if (have[i] && have[j] && ((i & j) == 0)) {
                cout << "YES\n";
                return;
            }
            
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
#if 0
    while (true) {
        //guessed = false;
        solve(false);
        //assert(guessed);
    }
#endif
    
    return 0;
}