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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 1000100;
vector<int> g[MAXN], h[MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (u < v) {
            g[u].push_back(v);
        } else {
            h[v].push_back(u);
        }
    }

    vector<int> del(n);
    vector<int> used(n);

    for (int v = 0; v < n; ++v) {
        if (del[v]) {
            continue;
        }

        for (int u : g[v]) {
            del[u] = 1;
        }

        used[v] = 1;
    }

    vector<int> res;
    for (int v = n - 1; v >= 0; --v) {
        if (!used[v]) {
            continue;
        }
        bool ok = false;
        for (int u : h[v]) {
            ok |= (used[u] == 2);
        }
        if (!ok) {
            used[v] = 2;
            res.push_back(v);
        }
    }

    cout << sz(res) << endl;
    for (int v : res) {
        cout << v + 1 << " ";
    }
    cout << endl;
}