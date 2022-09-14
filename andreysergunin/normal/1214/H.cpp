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
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 200200;

int n, k;
vector<int> g[MAXN];
int dist[2][MAXN];

pii dfs(int v, int p = -1) {
    pii res = {-1, v};
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        res = max(res, dfs(u, v));
    }
    ++res.first;
    return res;
}

void dfs1(int v, int k, int d, int p = -1) {
    dist[k][v] = d;
    for (int u : g[v]) {    
        if (u == p) {
            continue;
        }
        dfs1(u, k, d + 1, v);
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

    cin >> n >> k;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    pii p = dfs(0);
    int u = p.second;
    p = dfs(u);
    int v = p.second;
    int len = p.first;
    // cout << len << endl;
    
    dfs1(u, 0, 0);
    dfs1(v, 1, 0);

    // cout << u << " " << v << endl;

    // for (int k = 0; k < 2; ++k) {
    //     for (int i = 0; i < n; ++i) {
    //         cout << dist[k][i] << " ";
    //     }
    //     cout << endl;
    // }


    vector<int> col(n);

    for (int i = 0; i < n; ++i) {
        int d = (dist[0][i] + dist[1][i] - len) / 2;

        int a = dist[0][i] - d;
        int b = dist[1][i] - d;

        // cout << a << " " << b << " " << d << endl;
        
        if (d == 0) {
            col[i] = dist[0][i] % k;
            continue;
        }

        if (a + d >= k - 1 && b + d >= k - 1 && d <= k - 2) { 
            cout << "No" << endl;
            return 0;
        }

        if (a >= b) {
            col[i] = (a - (k - d)) % k;
            if (col[i] < 0) {
                col[i] += k;
            }
        } else {   
            col[i] = (a + (k - d)) % k;
            if (col[i] < 0) {
                col[i] += k;
            }
        }
    }

    cout << "Yes" << endl;
    for (int c : col) {
        cout << c + 1 << " ";
    }
    cout << endl;


#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}