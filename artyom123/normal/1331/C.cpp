#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    while (n) {
        s += char('0' + n % 2);
        n /= 2;
    }
    while (s.size() != 6)
        s += '0';
    reverse(s.begin(), s.end());
    string res = "";
    while (res.size() != 6)
        res += '0';
    res[0] = s[0];
    res[5] = s[1];
    res[3] = s[2];
    res[2] = s[3];
    res[4] = s[4];
    res[1] = s[5];
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        if (res[i] == '1') {
            ans += (1 << (5 - i));
        }
    }
    cout << ans << endl;
    return 0;
}