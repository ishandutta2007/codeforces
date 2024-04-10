#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <bool> now(n, true);
    char last = s[0];
    int l = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == last) {
            now[l] = false;
            l = i;
        }
        else {
            if (i != n - 1) {
                last = s[i + 1];
                l = i + 1;
            }
            ++i;
        }
    }
    int kol = 0;
    for (int i = 0; i < n; ++i) {
        kol += now[i];
    }
    if (kol % 2 == 1) {
        cout << n - kol + 1 << "\n";
        for (int i = 0; i < n && kol > 1; ++i) {
            if (now[i]) {
                cout << s[i];
                --kol;
            }
        }
    }
    else {
        cout << n - kol << "\n";
        for (int i = 0; i < n; ++i) {
            if (now[i]) cout << s[i];
        }
    }
}