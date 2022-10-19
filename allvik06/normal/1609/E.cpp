#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
const int INF = 1e9;

const int cnt = 5;
vector <vector <int>> result_mask;

inline void build_mask() {
    for (int mask1 = 0; mask1 < (1 << cnt); ++mask1) {
        for (int mask2 = 0; mask2 < (1 << cnt); ++mask2) {
            int mask = 0;
            for (int i = 0; i < 5; ++i) {
                if (((mask1 >> i) & 1) || ((mask2 >> i) & 1)) mask |= (1 << i);
            }
            if ((mask1 & 1) && (mask2 & 2)) mask |= (1 << 3);
            if ((mask1 & 2) && (mask2 & 4)) mask |= (1 << 4);
            if ((mask1 & 1) && (mask2 & 16)) mask = -1;
            if ((mask1 & 8) && (mask2 & 4)) mask = -1;
            result_mask[mask1][mask2] = mask;
        }
    }
}

vector <int> merge(const vector <int>& a, const vector <int>& b) {
    vector <int> ans(1 << cnt, INF);
    for (int mask1 = 0; mask1 < (1 << cnt); ++mask1) {
        for (int mask2 = 0; mask2 < (1 << cnt); ++mask2) {
            if (result_mask[mask1][mask2] != -1) ans[result_mask[mask1][mask2]] = min(ans[result_mask[mask1][mask2]], a[mask1] + b[mask2]);
        }
    }
    return ans;
}

vector <vector <int>> t;

inline void build(int len, const string& s) {
    for (int i = 2 * len - 1; i > 0; --i) {
        if (i >= len) {
            int pos = i - len;
            if (pos < (int)s.size()) {
                t[i][1] = t[i][2] = t[i][4] = 1;
                t[i][1 << (s[pos] - 'a')] = 0;
            } else {
                t[i][0] = 0;
            }
        } else {
            t[i] = merge(t[2 * i], t[2 * i + 1]);
        }
    }
}

inline void upd(int len, int i, char c) {
    i += len;
    t[i][1] = t[i][2] = t[i][4] = 1;
    t[i][1 << (c - 'a')] = 0;
    i >>= 1;
    while (i) {
        t[i] = merge(t[2 * i], t[2 * i + 1]);
        i >>= 1;
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    result_mask.resize(1 << cnt, vector <int> (1 << cnt));
    build_mask();
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int len = 1 << (int)ceil(log2(n));
    t.resize(2 * len, vector <int> (1 << cnt, INF));
    build(len, s);
    while (q--) {
        int pos;
        char c;
        cin >> pos >> c; --pos;
        upd(len, pos, c);
        cout << *min_element(t[1].begin(), t[1].end()) << "\n";
    }
}

/*

 */