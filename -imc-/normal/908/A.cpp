#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
    string s;
    cin >> s;
    
    int answer = 0;
    for (char c: s) {
        bool isDigit = (c >= '0' && c <= '9');
        bool isEven = (c >= '0' && c <= '9' && (c - '0') % 2 == 0);
        bool isX = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        
        if ((!isDigit && isX) || (isDigit && !isEven)) answer++;
    }
    cout << answer << "\n";
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