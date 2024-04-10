#include <bits/stdc++.h>

using namespace std;
const int maxn = (int)1e5 + 100;
vector<int> g[maxn];
int used[maxn];
int d[maxn];
vector<int> c[maxn];
int k = 2;
int n, m;
int p[maxn];
void dfs(int v, int pa) {
    d[v] = d[pa] + 1;
    used[v] = 1;
    p[v] = pa;
    for(int to: g[v]) {
        if(to == pa) continue;
        if(used[to] == 1) {
            long long cur = (d[v] - d[to] + 1);
            if(cur * cur >= n) {
                int t = v;
                vector<int> path;
                while(t != to) {
                    path.push_back(t);
                    t = p[t];
                }
                path.push_back(to);
                cout << 2 << "\n" << path.size() << "\n";
                for(int x: path) {
                    cout << x << " ";
                }
                exit(0);
             }
            k = max((int)cur, k);
        } else if(used[to] == 0){
            dfs(to, v);
        }
    }
    used[v] = 2;
}
int main(){
    cin >> n >> m;
    map<pair<int, int>, int> M;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        M[{u, v}] = 1;
        M[{v, u}] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        c[d[i] % k].push_back(i);
    }
    int ne = 0;
    while(ne * ne < n) ne++;
    for(int i = 0; i < k; i++) {
        long long sz = c[i].size();
        if(sz >= ne) {
            cout << 1 << "\n";
            for(int j = 0; j < ne; j++) {
                cout << c[i][j] << " ";
            }
            exit(0);
        }
    }
}