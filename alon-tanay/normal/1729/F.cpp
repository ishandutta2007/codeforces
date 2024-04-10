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

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n = str.length();
        vector<int> as(n);
        vector<int> pres(n + 1);
        int idx = 0;
        int sum = 0;
        for (int &a : as) {
            char c = str[idx];
            a = c - '0';
            sum += a;
            pres[++idx] = sum;
        }
        int w, m;
        cin >> w >> m;
        vector<vector<int>> lcs(9);
        for (int i = w - 1; i < n; i++) {
            // cout << i << ": " << (pres[i + 1] - pres[i - w + 1]) % 9 << endl;
            lcs[(pres[i + 1] - pres[i - w + 1]) % 9].push_back(i - w + 1);
        }
        for (int i = 0; i < m; i++) {
            int l, r, k;
            cin >> l >> r >> k;
            int c = (pres[r] - pres[l - 1]) % 9;
            pi res = {1e9, 1e9};
            for (int j = 0; j < 9; j++) {
                if (lcs[j].empty()) {
                    continue;
                }
                int L = lcs[j][0];
                int b = (((k - j * c) % 9) + 9) % 9;
                int idx = (b == j);
                if (lcs[b].size() <= idx) {
                    continue;
                }
                res = min(res, {L, lcs[b][idx]});
            }
            if (res.f == 1e9) {
                res = {-2, -2};
            }
            cout << res.f + 1 << " " << res.s + 1 << "\n";
        }
    }
    return 0;
}