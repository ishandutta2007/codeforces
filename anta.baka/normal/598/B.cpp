#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        k %= r - l + 1;
        string t = s.substr(r - k + 1, k);
        t += s.substr(l, r - l + 1 - k);
        for(int j = 0; j < t.length(); j++)
            s[j + l] = t[j];
    }
    cout << s;
}