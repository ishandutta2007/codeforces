#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

//#define int li

void solve(bool read) {
    int n;
    cin >> n;
    
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        
        if (s.count(x))
            cout << "YES\n";
        else {
            cout << "NO\n";
            s.insert(x);
        }
    }
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
        guessed = false;
        solve(false);
        assert(guessed);
    }
#endif
    
    return 0;
}