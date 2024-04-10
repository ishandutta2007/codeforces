#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
    string pass;
    cin >> pass;
    
    int n;
    cin >> n;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    for (int off = 0; off < 2; off++) {
        string x = pass;
        int pos = 0;
        
        if (off == 1) {
            for (int i = 0; i < n; i++) {
                if (s[i][1] == x[0]) {
                    pos = 1;
                    break;
                }
            }
            
            if (pos == 0) continue;
        }
        
        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (s[i][0] == x[pos] && (pos + 1 >= x.size() || s[i][1] == x[pos + 1])) {
                    found = true;
                    pos += 2;
                    //printf("can %d\n", i);
                    break;
                }
            }
            
            if (pos >= x.size()) {
                //printf("pos %d\n", pos);
                cout << "YES\n";
                return;
            }
            
            if (!found) break;
        }
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