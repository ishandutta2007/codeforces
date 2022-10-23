#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s.begin(), s.end(), [](string x, string y) {
        int lx = x.size(), ly = y.size();
        if (lx == ly) {
            return x < y;
        } else {
            return lx < ly;
        }
    });
    for (int i = 0; i < n - 1; ++i) {
        string a = s[i], b = s[i + 1];
        bool ok = false;
        int la = a.size(), lb = b.size();
        for (int j = 0; j + la <= lb; ++j) {
            ok |= a == b.substr(j, la);
        }
        if (not ok) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (string a : s) cout << a << "\n";
    return 0;
}