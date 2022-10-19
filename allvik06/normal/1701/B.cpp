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
        vector <int> p(n);
        vector <bool> used(n + 1);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            while (used[cur]) ++cur;
            if (i == 0) {
                p[i] = 1;
                used[1] = true;
            } else {
                if (p[i - 1] * 2 <= n) {
                    p[i] = p[i - 1] * 2;
                    used[p[i]] = true;
                } else {
                    p[i] = cur;
                    used[cur] = true;
                }
            }
        }
        cout << "2\n";
        for (int i : p) cout << i << ' ';
        cout << "\n";
    }
}

/*

 */