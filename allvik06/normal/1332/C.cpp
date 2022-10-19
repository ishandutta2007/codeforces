#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector <bool> used(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            vector <int> now(26);
            int c = 0;
            for (int j = i; j < n; j += k) {
                now[s[j] - 'a']++;
                ++c;
                used[j] = true;
            }
            for (int j = n - i - 1; j >= 0; j -= k) {
                if (!used[j]) {
                    now[s[j] - 'a']++;
                    ++c;
                    used[j] = true;
                }
            }
            int maxx = 0;
            for (int j = 0; j < 26; ++j) {
                if (maxx < now[j]) {
                    maxx = now[j];
                }
            }
            ans += c - maxx;
        }
        cout << ans << "\n";
    }
    return 0;
}