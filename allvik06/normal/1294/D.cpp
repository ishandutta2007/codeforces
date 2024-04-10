#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int q, x;
    cin >> q >> x;
    ++q;
    vector <int> a(x);
    set <pair <int, int>> s;
    for (int i = 0; i < x; ++i) {
        s.insert({0, i});
    }
    while (--q) {
        int tmp;
        cin >> tmp;
        tmp %= x;
        s.erase({a[tmp], tmp});
        s.insert({a[tmp] + 1, tmp});
        ++a[tmp];
        pair <int, int> now = *s.begin();
        cout << x * now.first + now.second << "\n";
    }
    return 0;
}