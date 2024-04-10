#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long l, r;
        cin >> l >> r;
        if (l == 0) {
            if (r == 0) {
                cout << "0\n";
                continue;
            }
        } else {
            --l;
        }
        pair<int, long long> ans(0, 0);
        for (long long k = 60; k >= 0; --k)
            if (((l >> k) & 1) == 0) {
                long long t = (l >> k) << k;
                t |= (1ll << k);
                while (t <= r) {
                    ans = max(ans, make_pair(__builtin_popcountll(t), -t));
                    t |= (t + 1);
                }
            }
        cout << -ans.second << "\n";
    }

    return 0;
}