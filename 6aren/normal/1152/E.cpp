#include <bits/stdc++.h>

using namespace std;

struct EulerianGraph {
    vector< vector< pair<int, int> > > a;
    int num_edges;

    EulerianGraph(int n) {
        a.resize(n + 1);
        num_edges = 0;
    }

    void add_edge(int u, int v, bool undirected = true) {
        a[u].push_back(make_pair(v, num_edges));
        if (undirected) a[v].push_back(make_pair(u, num_edges));
        num_edges++;
    }

    vector<int> get_eulerian_path() {
        vector<int> path, s;
        vector<bool> was(num_edges);
        
        // s.push_back(1);
        // start of eulerian path
        // directed graph: deg_out - deg_in == 1
        // undirected graph: odd degree
        // for eulerian cycle: any vertex is OK
        int start = -1, cnt = 0;;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].size() % 2) start = i, cnt++;
        }
        if (cnt == 0) {
            start = 0;
        } else if (cnt != 2) return vector<int>();
        s.push_back(start);
        
        while (!s.empty()) {
            int u = s.back();
            bool found = false;
            while (!a[u].empty()) {
                int v = a[u].back().first;
                int e = a[u].back().second;
                a[u].pop_back();
                if (was[e]) continue;
                was[e] = true;
                s.push_back(v);
                found = true;
                break; 
            }
            if (!found) {
                path.push_back(u);
                s.pop_back();
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> b(n - 1), c(n - 1), toComp;
    for (int &e : b) cin >> e, toComp.push_back(e);
    for (int &e : c) cin >> e, toComp.push_back(e);
    sort(toComp.begin(), toComp.end());
    toComp.erase(unique(toComp.begin(), toComp.end()), toComp.end());
    for (int &e : b) e = lower_bound(toComp.begin(), toComp.end(), e) - toComp.begin();
    for (int &e : c) e = lower_bound(toComp.begin(), toComp.end(), e) - toComp.begin();
    EulerianGraph eulerian(2 * n + 2);
    for (int i = 0; i < n - 1; i++) {
        if (b[i] > c[i]) return cout << -1 << '\n', 0;
        eulerian.add_edge(b[i], c[i], true);
    }  

    vector<int> path = eulerian.get_eulerian_path();

    if (path.size() != n) {
        return cout << -1 << '\n', 0;
    }

    for (int e : path) cout << toComp[e] << " ";
    cout << "\n";

    return 0;
}