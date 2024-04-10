#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

inline int gcd(int a, int b) {
    for (; b > 0; a %= b, swap(a, b)) {}
    return a;
}

struct trio {
    int sum = 0, maxx = 0, minn = 0;
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            if (c == '-') a[i] = -1;
            else a[i] = 1;
        }
        vector <trio> pref(n), suf(n);
        vector <trio> pref1(n), suf1(n);
        if (a[0] == 1) {
            pref[0].sum = pref[0].maxx = 1;
        } else {
            pref[0].sum = pref[0].minn = -1;
        }
        for (int i = 1; i < n; ++i) {
            pref[i].sum = pref[i - 1].sum + a[i];
            pref[i].minn = min(pref[i - 1].minn, pref[i].sum);
            pref[i].maxx = max(pref[i - 1].maxx, pref[i].sum);
        }
        if (a.back() == 1) {
            suf[n - 1].sum = suf[n - 1].maxx = 1;
        } else {
            pref[n - 1].sum = suf[n - 1].minn = -1;
        }
        for (int i = n - 2; i >= 0; --i) {
            suf[i].sum = suf[i + 1].sum + a[i];
            suf[i].minn = min(0, suf[i + 1].minn + a[i]);
            suf[i].maxx = max(0, suf[i + 1].maxx + a[i]);
        }
        while (m--) {
            int l, r;
            cin >> l >> r; --l; --r;
            int minn = 0, maxx = 0, sum = 0;
            if (l > 0) {
                minn = min(minn, pref[l - 1].minn);
                maxx = max(maxx, pref[l - 1].maxx);
                sum = pref[l - 1].sum;
            }
            if (r < n - 1) {
                minn = min(minn, sum + suf[r + 1].minn);
                maxx = max(maxx, sum + suf[r + 1].maxx);
            }
            cout << maxx - minn + 1 << "\n";
        }
    }
}