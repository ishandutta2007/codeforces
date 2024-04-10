#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (s.size() > k) {
            cout << -1 << "\n";
            continue;
        }
        cout << 100 * k << "\n";
        for (int i = 0; i < 100; i++) {
            for (auto &c : s) {
                cout << c << " ";
            }
            for (int j = 0; j < k - s.size(); j++) {
                cout << 1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}