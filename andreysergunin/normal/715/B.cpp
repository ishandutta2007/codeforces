#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <tuple>
#include <functional>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fs first
#define sc second

typedef pair<int, int> pii;

const long long INF = 1e18;

struct Edge {
    int from;
    int to;
    bool var;
    long long cost;
    int num;
};

vector<Edge> edges;

vector<vector<int>> g;

vector<long long> dist;
vector<int> prv;

void dejekstra(int s, int forbid) {
    int n = sz(g);
    dist.assign(n, INF);

    vector<bool> used(n);
    dist[s] = 0;
    prv.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || dist[j] < dist[v])) 
                v = j;
        // cout << v << endl;
        for (int j = 0; j < sz(g[v]); ++j) {
            Edge e = edges[g[v][j]];
            if (e.var && e.num > forbid)
                continue;

            if (dist[e.to] > dist[v] + e.cost) {
                prv[e.to] = g[v][j];
                dist[e.to] = dist[v] + e.cost;
            }
        }
        used[v] = true;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m, s, t;
    long long len;
    cin >> n >> m >> len >> s >> t;
    g.resize(n);

    vector<int> arr;

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(sz(edges));
        edges.push_back({u, v, c == 0, max(1, c), i});
        g[v].push_back(sz(edges));
        edges.push_back({v, u, c == 0, max(1, c), i});
        if (c == 0)
            arr.push_back(i);
    }

    dist.resize(n, INF);
    prv.resize(n, -1);

    dejekstra(s, -1);

    if (dist[t] < len) {
        cout << "NO" << endl;
        return 0;
    }

    int l = -1, r = sz(arr);
    while (r - l > 1) {
        int mid = (l + r) / 2;

        dejekstra(s, arr[mid]);


        if (dist[t] <= len)
            r = mid;
        else
            l = mid;
    }

    dejekstra(s, (r == sz(arr) ? m : arr[r]));

    if (dist[t] > len) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = r + 1; i < sz(arr); ++i) {
        edges[2 * arr[i]].cost = 1e9;
        edges[2 * arr[i] + 1].cost = 1e9;   
    }

    if (r != sz(arr)) {
        edges[2 * arr[r]].cost += len - dist[t];
        edges[2 * arr[r] + 1].cost = len - dist[t];   
    }
    

    cout << "Yes" << endl;
    for (int i = 0; i < m; ++i)
        cout << edges[2 * i].from << " " << edges[2 * i].to << " " << edges[2 * i].cost << endl;




    return 0;
}