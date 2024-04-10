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
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int now = 0;
        if (s.back() == 'A') {
            cout << "NO\n";
            continue;
        }
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[i] == 'A') {
                now = max(now - 1, 0LL);
            } else {
                ++now;
            }
        }
        if (now == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}