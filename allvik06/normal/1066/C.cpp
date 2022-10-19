#include <bits/stdc++.h>

using namespace std;

signed main() {
    unordered_map <int, int> a;
    int q;
    cin >> q;
    vector <int> b(2 * q + 2);
    char c;
    cin >> c;
    int x;
    cin >> x;
    int l, r;
    l = r = q;
    a[x] = l;
    for (int i = 0; i < q - 1; ++i) {
        cin >> c;
        if (c == 'L') {
            --l;
            cin >> x;
            b[l] = x;
            a[x] = l;
        }
        else if (c == 'R') {
            ++r;
            cin >> x;
            b[r] = x;
            a[x] = r;
        }
        else {
            cin >> x;
            cout << min(a[x] - l, r - a[x]) << "\n";
        }
    }
    return 0;
}