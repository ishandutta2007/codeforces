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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i].f >> a[i].s;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool ans1 = 1;
            for (int j = 0; j < n; ++j) {
                if (abs(a[i].f-a[j].f)+abs(a[i].s-a[j].s) > k)
                    ans1 = 0;
            }
            if (ans1)
                ans = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}