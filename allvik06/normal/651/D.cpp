#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 7;


signed main() {
    int n, t, a, b;
    cin >> n >> a >> b >> t;
    string s;
    cin >> s;
    int maxx = 0;
    vector <int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i];
        if (s[i] == 'w') {
            pref[i + 1] += b;
        }
    }
    for (int i = 0; i < n; ++i) {
        int tmp = i * a + i + 1 + pref[i + 1], cha = i + 1;
        if (tmp > t) continue;
        tmp += i * a;
        int l = i, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (tmp + (a + 1) * (n - m) + pref[n] - pref[m] <= t) {
                r = m;
            }
            else {
                l = m;
            }
        }
        cha += n - r;
        maxx = max(maxx, cha);
    }
    for (int i = 1; i < n; ++i) {
        int tmp = (n - i) * a + n - i+ pref[n] - pref[i] + 1 + pref[1], cha = n - i + 1;
        if (tmp > t) continue;
        tmp += (n - i) * a;
        int l = 0, r = i;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (tmp + (a + 1) * m + pref[m + 1] - pref[1] <= t) {
                l = m;
            }
            else {
                r = m;
            }
        }
        cha += l;
        maxx = max(maxx, cha);
    }
    cout << maxx;
    return 0;
}