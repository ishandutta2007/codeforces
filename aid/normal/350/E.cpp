#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<char> a(n);
    int v;
    for(int i = 0; i < k; i++) {
        int u;
        cin >> u;
        u--;
        a[u] = true;
        if(i == 0)
            v = u;
    }
    vector< vector<char> > g(n, vector<char>(n));
    int ed = 0, q = -1;
    for(int i = 0; i < n; i++)
        if(!a[i]) {
            g[i][v] = g[v][i] = true;
            ed++;
            if(q == -1)
                q = i;
        }
    if(q == -1) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++)
        if(i != v && a[i]) {
            g[i][q] = g[q][i] = true;
            ed++;
        }
    for(int i = 0; i < n && ed < m; i++)
        if(i != v)
            for(int j = 0; j < n && ed < m; j++)
                if(j != v && j != i && !g[i][j]) {
                    g[i][j] = g[j][i] = true;
                    ed++;
                }
    if(ed == m) {
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(g[i][j])
                    cout << i + 1 << ' ' << j + 1 << '\n';
    }
    else
        cout << -1 << '\n';
}