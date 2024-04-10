#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 100100;
const int P = 1e9 + 7;

void mul(int &a, int b) {
    a = (ll)a * b % P;
}

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

int binPow(int a, int b) {
    int res = 1;
    int x = a;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, x);
        }
        mul(x, x);
    }
    return res;
}

vector<int> xorConvolution(vector<int> cur) {
    int n = sz(cur);
    vector<int> ncur(n);
    for (int len = 1; len < n; len <<= 1) {
        for (int pos = 0; pos < n; pos += len) {
            for (int i = 0; i < len; ++pos, ++i) {
                ncur[pos] = cur[pos];
                add(ncur[pos], cur[pos + len]);

                ncur[pos + len] = cur[pos];
                sub(ncur[pos + len], cur[pos + len]);
            }
        }
        cur.swap(ncur);
    }
    return cur;
}

vector<int> xorProduct(vector<int> a, vector<int> b) {
    int n = 1;
    for (; n < max(sz(a), sz(b)); n <<= 1);
    a.resize(n);
    b.resize(n);
    a = xorConvolution(a);
    b = xorConvolution(b);
    int rn = binPow(n, P - 2);
    for (int i = 0; i < n; ++i) {
        mul(a[i], b[i]);
        mul(a[i], rn);
    }
    return xorConvolution(a);
}


vector<int> g[MAXN];
vector<int> w[MAXN];

vector<int> path;
vector<int> ed;

int x = 0;
vector<vector<int>> block;
int tin[MAXN];
int used[MAXN];

int tim = 0;

int dfs(int v, int p = -1) {
    used[v] = 1;
    tin[v] = tim++;
    path.push_back(v);

    int up = tin[v];

    for (int i = 0; i < sz(g[v]); ++i) {
        int u = g[v][i];
        if (u == p) {
            continue;
        }
        if (used[u] && tin[u] < tin[v]) {
            up = min(up, tin[u]);
            block.push_back({w[v][i]});

            for (int i = sz(path) - 1; path[i] != u; --i) {
                block.back().push_back(ed[i - 1]);
            }
        }
        if (!used[u]) {
            ed.push_back(w[v][i]);
            int fup = dfs(u, v);
            up = min(up, fup);
            if (fup > tin[v]) {
                // cout << "here " << v <<  " " << w[v][i] << endl;
                x ^= w[v][i];
            }
            ed.pop_back();
        }
    }
    path.pop_back();

    // cout << v << " " << up << endl;

    return up;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif  

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, ww;
        cin >> u >> v >> ww;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        w[u].push_back(ww);
        w[v].push_back(ww);
    }


    dfs(0);

    if (sz(block) == 0) {
        cout << x << " " << 1 << endl;
        return 0;
    }

    
    for (auto &vct : block) {
        int y = 0;
        for (int el : vct) {
            y ^= el;
        }
        for (int &el : vct) {
            el ^= y;
        }
        // vct.push_back(y);
    }
    // for (int i = 0; i < sz(block); ++i) {
    //     for (int el : block[i]) {
    //         cout << el << " ";
    //     }
    //     cout << endl;
    // }

    for (int &el : block[0]) {
        el ^= x;
    }

    int k = sz(block);
    vector<vector<int>> poly(k, vector<int>(1 << 17));
    vector<vector<int>> poly_cut(k, vector<int>(1 << 17));

    for (int i = 0; i < k; ++i) {
        for (int el : block[i]) {
            ++poly[i][el];
            poly_cut[i][el] |= 1;
        }
    }

    for (int i = 1; i < k; ++i) {
        poly[0] = xorProduct(poly[0], poly[i]);
        poly_cut[0] = xorProduct(poly_cut[0], poly_cut[i]);
        for (int j = 0; j < (1 << 17); ++j) {
            poly_cut[i][j] = (poly_cut[i][j] > 0);
        }
    }

    for (int i = 0; i < (1 << 17); ++i) {
        if (poly_cut[0][i] != 0) {
            cout << i << " " << poly[0][i] << endl;
            return 0;
        }
    }


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}