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
const int INF = 1e9;

inline void add(int i, int val, vector <int>& f) {
    for (++i; i > 0; i -= (i & (-i))) f[i] += val;
}

inline int get_sum(int i, int n, vector <int>& f) {
    int ans = 0;
    for (++i; i <= n; i += (i & (-i))) ans += f[i];
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int l = n * m;
        vector <int> p(l + 1);
        vector <int> flex(m);
        vector <int> f(m + 1);
        int cur = 0, prev = -INF;
        for (int i = 0; i < l; ++i) {
            if (s[i] == '1') {
                int o = i % m;
                if (!flex[o]) {
                    flex[o] = 1;
                    cur++;
                }
                if (i - prev >= m) {
                    add(m - 1, 1, f);
                } else {
                    int st = prev % m;
                    int last = (i - 1 + m) % m;
                    if (st <= last) {
                        add(last, 1, f);
                        add(st - 1, -1, f);
                    } else {
                        add(m - 1, 1, f);
                        add(st - 1, -1, f);
                        add(last, 1, f);
                    }
                }
                prev = i;
            }
            cout << cur + get_sum(i % m, m, f) << " ";
        }
        cout << "\n";
    }
    return 0;
}