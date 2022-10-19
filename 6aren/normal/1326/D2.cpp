#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
        vector<bool> check(n + 1);
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[n - i - 1] && ok) check[i] = 1;
            else {
                check[i] = 0;
                ok = 0;
            }
        }
        int ans = 0;
        int id = 0;
        int parity = 0;
        for (int i = 0; i < n; i++) {
            int l = i - d1[i] + 1;
            int r = i + d1[i] - 1;
            int t = min(l - 1, n - r - 2);
            if (t == -1) {
                if (ans > d1[i] * 2 - 1) continue;
                ans = d1[i] * 2 - 1;
                id = i;
                parity = 1;
                continue;
            }
            if (!check[t]) continue;
            if (d1[i] * 2 - 1 + 2 * (t + 1) > ans) {
                ans = d1[i] * 2 - 1 + 2 * (t + 1);
                id = i;
                parity = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            int l = i - d2[i];
            int r = i + d2[i] - 1;
            int t = min(l - 1, n - r - 2);
            // cout << i << ' ' << d2[i] << ' ' << t << endl;
            if (t == -1) {
                if (ans > d2[i] * 2) continue;
                ans = d2[i] * 2;
                id = i;
                parity = 0;
                continue;
            }
            if (!check[t]) continue;
            if (d2[i] * 2 + 2 * (t + 1) > ans) {
                ans = d2[i] * 2 + 2 * (t + 1);
                id = i;
                parity = 0;
            }
        }
        int l, r, t;
        if (parity == 1) {
            l = id - d1[id] + 1;
            r = id + d1[id] - 1;
            t = min(l - 1, n - r - 2);
        } else {
            l = id - d2[id];
            r = id + d2[id] - 1;
            t = min(l - 1, n - r - 2);
        }
        for (int i = 0; i <= t; i++) {
            cout << s[i];
        }
        for (int i = l; i <= r; i++) {
            cout << s[i];
        }
        for (int i = n - 1 - t; i <= n - 1; i++) {
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}