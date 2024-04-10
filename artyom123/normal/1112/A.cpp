#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> p(n);
    vector <int> s(n);
    for (auto &c : p) {
        cin >> c;
    }
    for (auto &c : s) {
        cin >> c;
    }
    vector <int> a(k);
    for (auto &c : a) {
        cin >> c;
    }
    int ans = 0;
    for (auto &c : a) {
        int now = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[c - 1] && i != c - 1 && p[i] > p[c - 1]) {
                now++;
            }
        }
        if (now > 0) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}