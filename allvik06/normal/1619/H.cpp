#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
//#define int long long
const int k = 475;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    vector <int> p(n), pr(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
        pr[p[i]] = i;
    }
    vector <int> nxt(n);
    for (int i = 0; i < n; ++i) {
        int cur = i;
        for (int j = 0; j < k; ++j) {
            cur = p[cur];
        }
        nxt[i] = cur;
    }

    auto upd = [&](int x) {
        vector <int> nx;
        int cur = x;
        for (int j = 0; j <= k; ++j) {
            nx.push_back(cur);
            cur = p[cur];
        }
        cur = x;
        for (int j = 0; j <= k; ++j) {
            nxt[cur] = nx[k - j];
            cur = pr[cur];
        }
    };

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y; --x; --y;
            swap(p[x], p[y]);
            swap(pr[p[x]], pr[p[y]]);
            upd(x);
            upd(y);
        } else {
            int x, c;
            cin >> x >> c; --x;
            while (c) {
                if (c >= k) {
                    c -= k;
                    x = nxt[x];
                } else {
                    x = p[x];
                    c--;
                }
            }
            cout << x + 1 << "\n";
        }
    }
}

/*

 */