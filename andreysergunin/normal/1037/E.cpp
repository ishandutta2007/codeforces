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

const int MAXN = 3e5;

vector<int> g[MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> edges;
    vector<int> res(m + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        deg[i] = sz(g[i]);
    }

    int cur = n;
    queue<int> q;
    vector<int> dead(n);
    for (int i = 0; i < n; ++i) {
        if (deg[i] < k) {
            dead[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        --cur;
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (!dead[u]) {
                --deg[u];
                if (deg[u] == k - 1) {
                    dead[u] = 1;
                    q.push(u);
                }
            }    
        }
    }
    res[m] = cur;

    for (int i = m - 1; i >= 0; --i) {
        // cout << i << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << deg[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << dead[i] << " ";
        // }
        // cout << endl;

        int u, v;
        tie(u, v) = edges[i];

        g[u].pop_back();
        g[v].pop_back();

        if (!dead[u] && !dead[v]) {

            --deg[u];
            if (deg[u] == k - 1) {
                dead[u] = 1;
                q.push(u);
            }

            --deg[v];
            if (deg[v] == k - 1) {
                dead[v] = 1;
                q.push(v);
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     cout << deg[i] << " ";
        // }
        // cout << endl;
        //  for (int i = 0; i < n; ++i) {
        //     cout << dead[i] << " ";
        // }
        // cout << endl;



        while (!q.empty()) {
            --cur;
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (!dead[u]) {
                    --deg[u];
                    if (deg[u] == k - 1) {
                        dead[u] = 1;
                        q.push(u);
                    }
                }    
            }
        }
        res[i] = cur;

        // for (int i = 0; i < n; ++i) {
        //     cout << deg[i] << " ";
        // }
        // cout << endl;
        //  for (int i = 0; i < n; ++i) {
        //     cout << dead[i] << " ";
        // }
        // cout << endl;
    }

    for (int i = 1; i <= m; ++i) {
        cout << res[i] << endl;
    }

}