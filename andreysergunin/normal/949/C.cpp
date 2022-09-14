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
typedef pair<ll, ll> pll;
typedef long double ld;  

const int MAXN = 100100;

bool onStack[MAXN];
stack<int> path;
int lowLink[MAXN];
int curindex;
int ind[MAXN];
vector<vector<int>> components;
vector<int> g[MAXN];

void tarjan(int vertex) {
    onStack[vertex] = 1;
    path.push(vertex);
    ind[vertex] = curindex;
    lowLink[vertex] = ind[vertex];
    ++curindex;

    for (int to : g[vertex]) {
        if (ind[to] == -1) {
            tarjan(to);
            lowLink[vertex] = std::min(lowLink[vertex], lowLink[to]);
        } else if (onStack[to]) {
            lowLink[vertex] = std::min(lowLink[vertex], ind[to]);
        }
    }

    if (ind[vertex] == lowLink[vertex]) {
        components.push_back({});
        while (onStack[vertex]) {
            onStack[path.top()] = false;
            components.back().push_back(path.top());
            path.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 

    int n, m, h;
    cin >> n >> m >> h;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        // cout << c[u] << " " << c[v] << endl;
        if ((c[u] == h - 1 && c[v] == 0) || c[v] - c[u] == 1) {
            // cout << "!" << u << " " << v << endl;
            g[u].push_back(v);
        }
        swap(u, v);
        if ((c[u] == h - 1 && c[v] == 0) || c[v] - c[u] == 1) {
            // cout << "!" << u << " " << v << endl;
            g[u].push_back(v);
        }


    }

    for (int i = 0; i < n; ++i) {
        ind[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        if (ind[i] == -1) {
            tarjan(i);
        }
    }

    vector<int> col(n);
    for (int i = 0; i < sz(components); ++i) {
        for (int el : components[i]) {
            col[el] = i;
        }
    }

    vector<int> f(sz(components));

    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (col[u] != col[v]) {
                f[col[u]] = 1;
            }
        }
    }

    int ans = n;
    vector<int> s;
    for (int i = 0; i < n; ++i) {
        s.push_back(i);
    }

    for (int i = 0; i < sz(components); ++i) {   
        if (f[i] || sz(components[i]) >= ans) {
            continue;
        }
        ans = sz(components[i]);
        s = components[i];
    }

    cout << ans << endl;
    for (int i = 0; i < sz(s); ++i) {
        cout << s[i] + 1 << " ";
    }
    cout << endl;

    // cout << sz(components) << endl;

    // for (auto comp : components) {
    //     for (int el : comp) {
    //         cout << el << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}