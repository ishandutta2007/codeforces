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

vector<vector<int>> nei;
vector<ll> val;
ll res = 0;

ll rec(int node, ll k) {
    res += val[node] * k;
    int sz = nei[node].size();
    if (sz == 0) {
        return val[node];
    }
    vector<ll> opt;
    for (int ne : nei[node]) {
        opt.push_back(rec(ne, k / sz));
    }
    // cout << node << ": " << endl;
    // for (int i = 0; i < sz; i++) {
    //     cout << "  " << nei[node][i] << ": " << opt[i] << endl;
    // }
    sort(opt.begin(), opt.end());
    reverse(opt.begin(), opt.end());
    int r = k % sz;
    for (int i = 0; i < r; i++) {
        res += opt[i];
    }
    return opt[r] + val[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        res = 0;
        int n, k;
        cin >> n >> k;
        nei.clear();
        nei.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            nei[p].push_back(i);
        }
        val.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> val[i];
        }
        rec(1, k);
        cout << res << "\n";
    }
    return 0;
}

/*
1
5 4
1 2 1 3
6 2 1 5 7
*/