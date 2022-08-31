#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    int last = 0;
    for (int i = 1; i < (int) s.length(); i++) {
        if (s[i] == '0') {
            ans -= last;
            last *= 10;
            ans += last;
        }
        ans += (s[i] - '0');
        last = (s[i] - '0');
    }
    cout << ans + 1 << endl;
}