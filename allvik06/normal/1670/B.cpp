#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k;
        cin >> k;
        vector <char> all(k);
        for (int i = 0; i < k; ++i) cin >> all[i];
        int mx = 0;
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            bool ok = false;
            for (int j = 0; j < k; ++j) {
                if (s[i] == all[j]) ok = true;
            }
            if (ok) {
                mx = max(mx, i - prev);
                prev = i;
            }
        }
        cout << mx << "\n";
    }
    return 0;
}