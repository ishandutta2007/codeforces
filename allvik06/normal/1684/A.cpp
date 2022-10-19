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
#include <iomanip>

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
        if ((int)s.size() == 2) cout << s[1] << "\n";
        else {
            char mn = s[0];
            for (char c : s) mn = min(mn, c);
            cout << mn << "\n";
        }
    }
    return 0;
}