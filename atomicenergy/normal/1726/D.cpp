#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;


vector<vector<pair<int, int>>  > g;
vector<int> assignment;
vector<int> searched;
vector<int> parent;
vector<int> depth;

void dfs(int n, int p, int d) {
    searched[n] = 1;
    parent[n] = p;
    depth[n] = d;
    for (auto q : g[n]) {
        if (q.first == p) continue;
        if (searched[q.first]) continue;
        assignment[q.second] = 1;
        dfs(q.first, n, d+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        g = vector<vector<pair<int, int>>  >(n);
        assignment = vector<int>(m);
        searched = vector<int>(n);
        parent = vector<int>(n);
        depth = vector<int>(n);
        vector<pair<int, int> > edges(m);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[x - 1].push_back({ y - 1, i });
            g[y - 1].push_back({ x - 1, i });
            edges[i] = { x - 1, y - 1 };
        }
        if (m == n-1) {
            for (int i = 0; i < m; i++) {
                cout << '0';
            }
            cout << endl;
        }
        if (m == n || m == n + 1) {
            dfs(0, -1, 0);
            for (int i = 0; i < m; i++) {
                cout << assignment[i];
            }
            cout << endl;

        }
        if (m == n+2) {
            dfs(0, -1, 0);
            set<int> s;

            for (int i = 0; i < m; i++) {
                if (assignment[i] == 0) {
                    s.insert(edges[i].first);
                    s.insert(edges[i].second);
                }
            }
            if (s.size() == 3) {
                int mxd = -5;
                int mx = 0;
                for (auto z : s) {
                    if (depth[z] > mxd) {
                        mxd = depth[z];
                        mx = z;
                    }
                }
                bool b = true;
                for (int i = 0; i < m; i++) {
                    if (assignment[i] == 0 && (edges[i].first == mx || edges[i].second == mx) && b) {
                        b = false;
                        assignment[i] = 1;
                    }
                    if (edges[i].first == mx && edges[i].second == parent[mx]) assignment[i] = 0;
                    if (edges[i].first == parent[mx] && edges[i].second == mx) assignment[i] = 0;

                }
            }
            for (int i = 0; i < m; i++) {
                cout << assignment[i];
            }
            cout << endl;
        }
    }
}