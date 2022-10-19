#include <bits/stdc++.h>
using namespace std;

int n, g, cnt, a[26];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        if (a[i] & 1) cnt++;
    }
    if (cnt > 1) cout << "0\n";
    else cout << g << "\n";
    string str;
    for (int i = 0; i < n; i++) {
        a[i] /= g, str.append(string(a[i] / 2, 'a' + i));
    }
    for (int i = 0; i < n; i++) if (a[i] & 1) {
        str.push_back('a' + i);
    }
    for (int i = n - 1; ~i; i--) {
        str.append(string(a[i] / 2, 'a' + i));
    }
    while (g--) {
        cout << str;
        reverse(str.begin(), str.end());
    }
    return 0;
}