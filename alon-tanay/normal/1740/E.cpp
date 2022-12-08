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

const int mxN = 100005;
vector<int> cs[mxN];
bool line[mxN];
int mx_d[mxN];

void gen_line(int node) {
    if (cs[node].empty()) {
        line[node] = true;
        return;
    }
    for (int c : cs[node]) {
        gen_line(c);
        mx_d[node] = max(mx_d[node], mx_d[c] + 1);
    }
    if (cs[node].size() > 1) {
        return;
    }
    line[node] = line[cs[node][0]];
}

int dfs(int node) {
    int res = 0;
    for (int c : cs[node]) {
        res += dfs(c);
        // if (line[c]) {
        //     res++;
        // }
    }
    return max(res, mx_d[node] + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> ps(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        ps[i] = p;
        cs[p].push_back(i);
    }
    gen_line(1);
    cout << dfs(1) << "\n";
    return 0;
}