#line 2 "/Users/alex/Templates/template/template.hpp"
#ifdef PRAGMAS
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <codecvt>
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <thread>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>

#line 2 "/Users/alex/Templates/template/macro.hpp"

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int((v).size()))
#line 6 "/Users/alex/Templates/template/util.hpp"

template<typename T>
void unq(std::vector<T> &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
void unq(std::string &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
#line 79 "/Users/alex/Templates/template/template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;

namespace Quark {
    void solve();
};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Quark::solve();
}

#line 2 "main.cpp"

using namespace Quark;

#define int ll

struct DSU {
    vector<int> pa, ra;

    DSU() {}

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        pa.resize(n);
        ra.resize(n);
        iota(all(pa), 0);
        fill(all(ra), 1);
    }

    int get(int a) {
        if (pa[a] == a)
            return a;
        return pa[a] = get(pa[a]);
    }

    bool merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return false;
        }
        if (ra[b] > ra[a])
            swap(a, b);
        pa[b] = a;
        ra[a] += ra[b];
        return true;
    }
};

vector<pair<int, int>> edges;
vector<vector<int>> tree;

vector<int> used;
vector<int> pa;
vector<int> d;

void dfs1(int v) {
    used[v] = 1;
    for (int u : tree[v]) {
        if (!used[u]) {
            pa[u] = v;
            d[u] = d[v] + 1;
            dfs1(u);
        }
    }
}

int n;

const int LOG = 20;
vector<vector<int>> up;

void prepare_binup() {
    up.resize(n, vector<int> (LOG));
    for (int i = 0; i < n; i++) {
        up[i][0] = pa[i];
        if (up[i][0] == -1)
            up[i][0] = i;
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int goup(int a, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            a = up[a][i];
        }
    }
    return a;
}

int lca(int a, int b) {
    if (d[b] > d[a]) {
        swap(a, b);
    }
    a = goup(a, d[a] - d[b]);
    if (a == b) {
        return a;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return pa[a];
}

vector<int> val;

void dfs2(int v) {
    used[v] = 1;
    for (int u : tree[v]) {
        if (!used[u]) {
            dfs2(u);
            val[v] += val[u];
        }
    }
}

vector<int> tin;
vector<int> tup;
int cur_time = 0;

set<pair<int, int>> bridges;

void dfs3(int v, int pa=-1) {
    tup[v] = tin[v] = cur_time++;
    used[v] = 1;
    for (int u : tree[v]) {
        if (!used[u]) {
            dfs3(u);
            tup[v] = min(tup[v], tup[u]);
            if (tup[u] > tin[v]) {
                bridges.insert({u, v});
                bridges.insert({v, u});
            }
        } else if (u != pa) {
            tup[v] = min(tup[v], tin[u]);
        }
    }
}

vector<int> val2;

void dfs4(int v) {
    used[v] = 1;
    for (int u : tree[v]) {
        if (!used[u]) {
            val2[u] += val2[v];
            dfs4(u);
        }
    }
}


void Quark::solve() {
    int m;
    cin >> n >> m;
    DSU dsu(n);
    tree.resize(n);
    pa.resize(n, -1);
    val.resize(n);
    d.resize(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.push_back({a, b});
        if (dsu.merge(a, b)) {
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
    used.assign(n, 0);
    dfs1(0);
    prepare_binup();
    dsu.init(n);
    val2.resize(n);
    for (int i = 0; i < m; i++) {
        int a = edges[i].first;
        int b = edges[i].second;
        if (!dsu.merge(a, b)) {
            int c = lca(a, b);
            if (a == c) {
                val2[b]--;
                int pa = goup(b, d[b] - d[a] - 1);
                val2[pa]++;
            } else if (b == c) {
                swap(a, b);
                val2[b]--;
                int pa = goup(b, d[b] - d[a] - 1);
                val2[pa]++;
            } else {
                val2[0]++;
                val2[a]--;
                val2[b]--;
            }
        } 
    }
    used.assign(n, 0);
    dfs4(0);
    for (int i = 0; i < n; i++) {
        if (val2[i] || val[i]) {
            cout << '0';
        } else {
            cout << '1';
        }
    }
    cout << endl;
}