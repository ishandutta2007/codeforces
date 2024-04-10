#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, x, y, kol = 0;
    cin >> n;
    string s;
    cin >> x >> y >> s;
    reverse(s.begin(), s.end());
    for (int i = y + 1; i < x; ++i) {
        if (s[i] == '1') ++kol;
    }
    for (int i = 0; i < y; ++i) {
        if (s[i] == '1') ++kol;
    }
    if (s[y] == '0') ++kol;
    cout << kol;
}