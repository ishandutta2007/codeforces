#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>

using namespace std;
#define int long long

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            --b[i];
        }
        if (a.back() != b.back()) {
            cout << "NO\n";
            continue;
        }
        vector <int> cha(n);
        int cur = n - 2;
        bool ok = true;
        for (int i = n - 2; i >= 0; --i) {
            if (b[i] == b[i + 1]) {
                ++cha[b[i]];
            } else {
                while (a[cur] != b[i]) {
                    if (cha[a[cur]]) {
                        cha[a[cur]]--;
                        cur--;
                    } else {
                        ok = false;
                        break;
                    }
                }
                cur--;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}