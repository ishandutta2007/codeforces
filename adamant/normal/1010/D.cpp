#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) begin(x), end(x)

typedef double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}
ftype cross(point a, point b) {
    return (conj(a) * b).y();
}

const ftype pi = acos(-1);

const int maxn = 1e6 + 42;

vector<int> g[maxn];
string type[maxn];
int val[maxn], can_change[maxn];

void dfs_val(int v = 0) {
    if(type[v] == "IN") {
        val[v] = g[v][0];
    } else if(type[v] == "NOT") {
        dfs_val(g[v][0]);
        val[v] = !val[g[v][0]];
    } else if(type[v] == "OR") {
        dfs_val(g[v][0]);
        dfs_val(g[v][1]);
        val[v] = val[g[v][0]] | val[g[v][1]];
    } else if(type[v] == "XOR") {
        dfs_val(g[v][0]);
        dfs_val(g[v][1]);
        val[v] = val[g[v][0]] ^ val[g[v][1]];
    } else if(type[v] == "AND") {
        dfs_val(g[v][0]);
        dfs_val(g[v][1]);
        val[v] = val[g[v][0]] & val[g[v][1]];
    }
}

void dfs_change(int v = 0) {
    if(type[v] == "IN") {
        return;
    } else if(type[v] == "NOT") {
        can_change[g[v][0]] = true;
        dfs_change(g[v][0]);
    } else {
        int L = g[v][0], R = g[v][1];
        if(type[v] == "OR") {
            if(val[L] == 0 && val[R] == 0) {
                can_change[L] = can_change[R] = 1;
                dfs_change(L), dfs_change(R);
            } else if(val[L] == 1 && val[R] == 0) {
                can_change[L] = 1;
                dfs_change(L);
            } else if(val[L] == 0 && val[R] == 1) {
                can_change[R] = 1;
                dfs_change(R);
            }
        } else if(type[v] == "AND") {
            if(val[L] == 1 && val[R] == 1) {
                can_change[L] = can_change[R] = 1;
                dfs_change(L), dfs_change(R);
            } else if(val[L] == 0 && val[R] == 1) {
                can_change[L] = 1;
                dfs_change(L);
            } else if(val[L] == 1 && val[R] == 0) {
                can_change[R] = 1;
                dfs_change(R);
            }
        } else if(type[v] == "XOR") {
            can_change[L] = can_change[R] = 1;
            dfs_change(L), dfs_change(R);
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> sz;
    sz["AND"] = sz["OR"] = sz["XOR"] = 2;
    sz["NOT"] = sz["IN"] = 1;
    vector<int> ins;
    for(int i = 0; i < n; i++) {
        cin >> type[i];
        g[i].resize(sz[type[i]]);
        for(auto &it: g[i]) {
            cin >> it;
            if(type[i] != "IN") {
                it--;
            }
        }

    }
    dfs_val();
    dfs_change();
    for(int i = 0; i < n; i++) {
        if(type[i] == "IN") {
            cout << (val[0] ^ can_change[i]);
        }
    }
    return 0;
}