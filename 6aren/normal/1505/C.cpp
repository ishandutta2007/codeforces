#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    bool ok = 1;
    for (int i = 2; i < s.size(); i++) {
        ok &= (s[i] - 'A' == ((s[i - 1] - 'A') + (s[i - 2] - 'A')) % 26);
    }
    cout << (ok ? "YES\n" : "NO\n");

    return 0;
}