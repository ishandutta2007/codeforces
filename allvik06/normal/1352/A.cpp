#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;
        int kol = 1;
        while (n > 0) {
            if (n % 10 != 0) {
                ans.push_back((n % 10) * kol);
            }
            n /= 10;
            kol *= 10;
        }
        cout << ans.size() << "\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}