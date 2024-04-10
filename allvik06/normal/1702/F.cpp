#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset <int> a, b;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b.insert(x);
        }
        bool ok = true;
        while (!a.empty()) {
            int mx1 = *a.rbegin();
            int mx2 = *b.rbegin();
            if (mx1 == mx2) {
                a.erase(a.find(mx1));
                b.erase(b.find(mx1));
                continue;
            }
            if (mx1 > mx2) {
                a.erase(a.find(mx1));
                if (mx1 % 2 == 1) {
                    ok = false;
                    break;
                }
                a.insert(mx1 / 2);
            } else {
                b.erase(b.find(mx2));
                if (mx2 / 2 == 0) {
                    ok = false;
                    break;
                }
                b.insert(mx2 / 2);
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

/*

 */