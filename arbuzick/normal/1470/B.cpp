#include <bits/stdc++.h>

//#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        unordered_map<int, int> m;
        vector<int> mn(n);
        int ans1 = 0;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            mn[i] = 1;
            for (int j = 2; j*j <= x; ++j) {
                int c = 0;
                while (x%j == 0) {
                    x /= j;
                    c++;
                }
                if (c%2 == 1) {
                    mn[i] *= j;
                }
            }
            if (x > 1) {
                mn[i] *= x;
            }
            m[mn[i]]++;
            ans1 = max(ans1, m[mn[i]]);
        }
        int ans2 = m[1];
        m[1] = 0;
        for (int i = 0; i < n; ++i) {
            if (m[mn[i]]%2 == 0) {
                ans2 += m[mn[i]];
                m[mn[i]] = 0;
            }
        }
        int q;
        cin >> q;
        while (q--) {
            long long w;
            cin >> w;
            if (w == 0) {
                cout << ans1 << '\n';
            } else {
                cout << max(ans1, ans2) << '\n';
            }
        }
    }
    return 0;
}