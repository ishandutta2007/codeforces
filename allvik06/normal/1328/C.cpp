#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        string a, b;
        a += "1";
        b += "1";
        int bol = 0;
        for (int i = 1; i < n; ++i) {
            if (x[i] == '0') {
                a += '0';
                b += '0';
            }
            else if (x[i] == '1') {
                if (bol == 0) {
                    a += '1';
                    b += '0';
                    bol = 1;
                }
                else if (bol == 1) {
                    a += '0';
                    b += '1';
                }
            }
            else {
                if (bol == 0) {
                    a += '1';
                    b += '1';
                }
                else {
                    a += '0';
                    b += '2';
                }
            }
        }
        cout << a << "\n" << b << "\n";
    }
    return 0;
}