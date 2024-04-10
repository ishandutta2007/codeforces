#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> pr0(n + 1), pr1(n + 1);
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                pr0[i + 1] = pr0[i] + a[i];
                pr1[i + 1] = pr1[i];
            }
            else {
                pr1[i + 1] = pr1[i] + a[i];
                pr0[i + 1] = pr0[i];
            }
        }
        vector<int> r(n + 1);
        for (int i = 0; i < n; ++i)
            r[i + 1] = pr1[i + 1] - pr0[i + 1];
        int ans = 0, min0 = r[1], min1 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ans = max(ans, r[i + 1] - min0);
                min0 = min(min0, r[i + 1]);
            }
            else {
                ans = max(ans, r[i + 1] - min1);
                min1 = min(min1, r[i + 1]);
            }
        }
        cout << pr0[n] + ans << "\n";
    }
    return 0;
}