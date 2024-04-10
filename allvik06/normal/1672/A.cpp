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
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x - 1;
        }
        if (sum % 2 == 0) {
            cout << "maomao90\n";
        } else {
            cout << "errorgorn\n";
        }
    }
    return 0;
}