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

        vector<int> bs(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> bs[i];
        }

        int k = 0;
        for (; k < n; k++) {
            if (bs[k + 1] <= k) {
                break;
            }
        }
        cout << k << "\n";
        vector<vector<int>> els(n + 2);
        for (int i = 1; i <= n; i++) {
            els[bs[i]].push_back(i);
        }
        int lst = els[0].empty() ? n + 1 : 0;
        while (els[lst].size()) {
            int en = els[lst][0];
            for (int el : els[lst]) {
                if (els[el].size()) {
                    en = el;
                    break;
                }
            }
            for (int el : els[lst]) {
                if (el == en) {
                    continue;
                }
                cout << el << " ";
            }
            cout << en << " ";
            els[lst].clear();
            lst = en;
        }
        cout << "\n";
    }
    return 0;
}