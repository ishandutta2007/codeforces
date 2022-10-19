#include <bits/stdc++.h>

#define int long long
#define double long double
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
        int n, m;
        cin >> m >> n;
        vector<int> k(m);
        for (int i = 0; i < m; ++i) {
            cin >> k[i], k[i]--;
        }
        sort(rall(k));
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        int ans = 0, p = 0;
        for (int i = 0; i < m; ++i) {
            if (p > k[i]) {
                ans += c[k[i]];
            } else  {
                if (c[p] == c[k[i]]) {
                    ans += c[k[i]];
                } else {
                    ans += c[p];
                    p++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}