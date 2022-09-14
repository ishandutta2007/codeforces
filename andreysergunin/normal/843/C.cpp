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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;

mt19937 rr(random_device{}());

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int MAXN = 3e5;

vector<int> g[MAXN];
int p[MAXN];
int w[MAXN];
int used[MAXN];

int deg[MAXN];

struct Request {
    int x, y, z;
};

vector<Request> req;

void request(int x, int y, int z) {
    req.push_back({x, y, z});
}

int dfs1(int v, int par = -1) {
    w[v] = 1;
    p[v] = par;
    for (int u : g[v]) {
        if (u == par)
            continue;
        w[v] += dfs1(u, v);
    }
    return w[v];
}

int last;

vector<int> leaves;
vector<int> path;

void getLeaves(int v, int par = -1) {
    if (deg[v] == 1) {
        leaves.push_back(v);
    }

    for (int u : g[v]) {
        if (u == par || used[u])
            continue;
        getLeaves(u, v);
    }
}

void getPath(int v, int c) {
    path.push_back(v);

    int u = leaves.back();
    leaves.pop_back();
    used[u] = true;

    int t = -1;

    for (int w : g[u]) {
        --deg[w];
        if (deg[w] == 1 && !used[w])
            leaves.push_back(w);
        if (!used[w])
            t = w;
    }

    request(v, c, u);
    if (t != -1) {
        getPath(u, t);
    } else {
        path.push_back(u);
    }
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(0);
    vector<int> cen;


    for (int v = 0; v < n; ++v) {
        bool f = true;
        if (2 * (n - w[v]) > n)
            f = false;
        for (int u : g[v]) {
            if (2 * w[u] > n && u != p[v])
                f = false;
        }
        if (f)
            cen.push_back(v);
    }

    for (int v : cen) {
        used[v] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int u : g[i]) {
            if (!used[u])
                ++deg[i];
        }
    }

    for (int v : cen) {
        for (int u : g[v]) {
            if (deg[u] == 0 || used[u])
                continue;
            leaves.clear();
            getLeaves(u);

            path.clear();
            getPath(v, u);

            int k = sz(path);
            for (int i = k - 4; i >= 0; --i)
                request(path[i], path[i + 1], path[k - 2]);
        }
    }

    cout << sz(req) << "\n";
    for (int i = 0; i < sz(req); ++i) {
        cout << req[i].x + 1 << " " << req[i].y + 1 << " " << req[i].z + 1 << "\n";
    } 



    return 0;
}