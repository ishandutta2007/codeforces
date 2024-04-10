#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read) {
    int a;
    cin >> a;
    
    if (a == 1)
        cout << "1 1\n1\n";
    else
        cout << (2 * a - 2) << " 2\n1 2\n";
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