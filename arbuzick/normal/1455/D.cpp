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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n*2; ++i) {
            bool s = 1;
            for (int j = 1; j < n; ++j)
                if (a[j] < a[j-1])
                    s = 0;
            if (s)
                break;
            if (i == n*2-1) {
                ans = -1;
                break;
            }
            for (int j = 0; j < n; ++j) {
                if (a[j] > x) {
                    swap(x, a[j]);
                    ans++;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}