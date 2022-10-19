#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

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
        vector <int> pos(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            pos[x] = i;
        }
        int ans = 1, cnt = 0, l = pos[0], r = pos[0];
        for (int i = 1; i < n; ++i) {
            if (pos[i] < l) {
                cnt += l - pos[i] - 1;
                l = pos[i];
            } else if (pos[i] > r) {
                cnt += pos[i] - r - 1;
                r = pos[i];
            } else {
                ans = (ans * cnt) % mod;
                cnt--;
            }
        }
        cout << ans << "\n";
    }
}

/*

 */