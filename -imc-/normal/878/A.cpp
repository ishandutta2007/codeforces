#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
    int n;
    cin >> n;
    
    const int max_bits = 10;
    
    const int X = 0, FLIP_X = 1, ZERO = 2, ONE = 3;
    
    vector<int> type(max_bits);
    
    for (int i = 0; i < n; i++) {
        string cmd;
        int num;
        cin >> cmd >> num;
        
        if (cmd == "^") {
            for (int i = 0; i < max_bits; i++)
                if (num & (1 << i))
                    type[i] ^= 1;
        }
        else if (cmd == "&") {
            for (int i = 0; i < max_bits; i++)
                if (!(num & (1 << i)))
                    type[i] = ZERO;
        }
        else if (cmd == "|") {
            for (int i = 0; i < max_bits; i++)
                if (num & (1 << i))
                    type[i] = ONE;
        }
    }
    
    int and_mask = 0, or_mask = 0, xor_mask = 0;
    for (int i = 0; i < max_bits; i++) {
        if (type[i] != ZERO)
            and_mask |= (1 << i);
        if (type[i] == ONE)
            or_mask |= (1 << i);
        if (type[i] == FLIP_X)
            xor_mask |= (1 << i);
    }
    
    cout << "3\n";
    cout << "^ " << xor_mask << "\n";
    cout << "& " << and_mask << "\n";
    cout << "| " << or_mask << "\n";
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