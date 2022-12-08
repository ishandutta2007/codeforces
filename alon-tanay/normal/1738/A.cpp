#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT =
#define enl "\n";
#define debug(k)                             \
    for (int _ = 0; _ < DEBUG_INDENT; _++) { \
        cout << "  ";                        \
    }                                        \
    cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template <typename T>
using pbds =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> as;
        vector<int> bs;
        vector<int> ts(n);
        for (int &t : ts) {
            cin >> t;
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            if (ts[i]) {
                as.push_back(x);
            } else {
                bs.push_back(x);
            }
        }
        sort(as.begin(), as.end());
        sort(bs.begin(), bs.end());
        int sz = min(as.size(), bs.size());
        if (as.size() == bs.size()) {
            cout << sum * 2 - min(as[0], bs[0]) << "\n";
            continue;
        }
        ll psum = 0;
        if (as.size() > bs.size()) {
            swap(as, bs);
        }
        for (int i = 0; i < bs.size() - as.size(); i++) {
            psum += bs[i];
        }
        cout << sum * 2 - psum << "\n";
    }
    return 0;
}