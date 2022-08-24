#include <bits/stdc++.h>

using namespace std;

int f['5'];

int main() {
    cin >> f['1'] >> f['2'] >> f['3'] >> f['4'];
    string s;
    int ans = 0;
    cin >> s;
    for (int i = 0; i < (int) s.length(); i++) {
        ans += f[s[i]];
    }
    cout << ans << endl;
}