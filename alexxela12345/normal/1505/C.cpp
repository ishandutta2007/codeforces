#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (char &c : s)
        c -= 'A';
    bool good = 1;
    for (int i = 2; i < (int) s.size(); i++) {
        if ((s[i - 2] + s[i - 1]) % 26 != s[i]) {
            good = 0;
        }
    }
    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}