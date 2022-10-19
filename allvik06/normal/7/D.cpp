#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;
#define ll long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    string s, tmp;
    cin >> tmp;
    int n = (int)tmp.size();
    for (int i = 0; i < n; ++i) {
        s += tmp[i];
        if (i < n - 1) s += "#";
    }
    int m = (int)s.size();
    vector <int> mon(m, 1);
    int l = 0, r = 0;
    for (int i = 1; i < m; ++i) {
        if (r >= i) {
            mon[i] = min(r - i + 1, mon[l + r - i]);
        }
        while (i + mon[i] < m && i - mon[i] >= 0 && s[i + mon[i]] == s[i - mon[i]]) ++mon[i];
        if (r < i + mon[i] - 1) {
            l = i - mon[i] + 1;
            r = i + mon[i] - 1;
        }
    }
    vector <int> p(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mon[i] >= i + 1) {
            p[i] = p[(i - 1) / 2] + 1;
            ans += p[i];
        }
    }
    cout << ans;
}