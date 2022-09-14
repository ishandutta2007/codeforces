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

const int MAXN = 100500;

vector<int> g[MAXN];
int used[MAXN];

void dfs(int v) {
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif  
        
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int res = n;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            --res;
            dfs(i);
        }
    }



    cout << m - res << endl;;



#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}