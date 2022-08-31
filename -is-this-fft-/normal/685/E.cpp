#include <iostream>
#include <vector>

using namespace std;

struct Query {
    int r, s, t, id;
};

const int MAX_N = 1e3 + 5;
const int MAX_M = 2e5 + 5;

pair<int, int> edges [MAX_M];
int minr [MAX_N][MAX_N];
vector<Query> queries [MAX_M];
bool ans [MAX_M];

int main () {
    ios::sync_with_stdio(false);
    
    int n, m, qc;
    cin >> n >> m >> qc;
    
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    for (int i = 0; i < qc; i++) {
        Query q;
        int l;
        cin >> l >> q.r >> q.s >> q.t;
        q.id = i;
        
        queries[l].push_back(q);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            minr[i][j] = MAX_M;
        }
    }
    
    for (int i = m; i >= 1; i--) {
        int u = edges[i].first;
        int v = edges[i].second;
        for (int t = 1; t <= n; t++) {
            minr[u][t] = min(minr[u][t], minr[v][t]);
            minr[v][t] = min(minr[v][t], minr[u][t]);
        }
        minr[u][v] = i;
        minr[v][u] = i;
        
        for (Query q : queries[i]) {
            ans[q.id] = minr[q.s][q.t] <= q.r;
        }
    }
    
    for (int i = 0; i < qc; i++) {
        cout << (ans[i] ? "Yes" : "No") << endl;
    }
}