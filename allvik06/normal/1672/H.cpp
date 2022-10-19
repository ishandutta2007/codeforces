#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector <int> p1(n), p2(n);
    for (int i = 1; i < n; ++i) {
        p1[i] = p1[i - 1];
        p2[i] = p2[i - 1];
        if (s[i] == '0' && s[i - 1] == '0') ++p1[i];
        if (s[i] == '1' && s[i - 1] == '1') ++p2[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r; --l; --r;
        cout << max(p1[r] - p1[l], p2[r] - p2[l]) + 1 << "\n";
    }
}