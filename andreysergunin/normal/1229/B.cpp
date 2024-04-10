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
using pll = pair<ll, ll>;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 100100;
const int P = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    a = (ll)a * b % P;
}

vector<int> g[MAXN];
ll x[MAXN];
vector<ll> gg[MAXN];
vector<int> h[MAXN];
int res;

void dfs(int v, int hh = 0, int p = -1) {   
    for (int i = 0; i < sz(gg[v]); ++i) {
        gg[v][i] = x[v] > 0 && gg[v][i] > 0 ? __gcd(x[v], gg[v][i]) : x[v] + gg[v][i];   
    }
    gg[v].push_back(x[v]);
    h[v].push_back(hh);
    int k = 0;
    for (int i = 1; i < sz(gg[v]); ++i) {
        if (gg[v][i] == gg[v][k]) {
            continue;
        } else {
            ++k;
            gg[v][k] = gg[v][i];
            h[v][k] = h[v][i];
        }
    }
    ++k;
    gg[v].resize(k);
    h[v].resize(k);
    h[v].push_back(hh + 1);

    for (int i = 0; i < k; ++i) {
        int cur = gg[v][i] % P;
        mul(cur, h[v][i + 1] - h[v][i]);
        add(res, cur);
    }

    h[v].pop_back();

    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        gg[u] = gg[v];
        h[u] = h[v];
        dfs(u, hh + 1, v);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    res = 0;
    dfs(0);

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < sz(gg[i]); ++j) {
    //         cout << gg[i][j] << " ";
    //     }
    //     cout << endl;
    //     for (int j = 0; j < sz(gg[i]); ++j) {
    //         cout << h[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << 1000000000ll * 11 * 5 % P << endl;;
    cout << res << endl;


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}