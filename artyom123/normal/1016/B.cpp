#include <bits/stdc++.h>

using namespace std;

const int p = 1e9 + 7;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    string now = "";
    vector <bool> a(n);
    for (int i = 0; i < n; i++) {
        if (now.size() == m) {
            now.erase(now.begin());
        }
        now += s[i];
        if (now == t) {
            a[i - m + 1] = true;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ans = 0;
        string now = "";
        for (int j = l; j + m - 1 <= r; j++) {
            if (a[j] == true) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}