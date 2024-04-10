#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    unordered_map <int, int> v;
    while (t--) {
        int a, b, sum = 0;
        cin >> a >> b;
        vector <int> ans(a * b), pref(a * b);
        for (int i = 0; i < a * b; ++i) {
            if ((i % a) % b == (i % b) % a) {
                ans[i] = 1;
                ++sum;
            }
            if (i != 0) {
                pref[i] = pref[i - 1] + ans[i];
            } else {
                pref[i] = ans[i];
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r; l--;
            int res1 = sum * (l / (a * b)) + pref[l % (a * b)];
            int res2 = sum * (r / (a * b)) + pref[r % (a * b)];
            cout << r - l - (res2 - res1) << "\n";
        }
    }
    return 0;
}