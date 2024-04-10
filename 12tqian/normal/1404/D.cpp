#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}"; }

int main() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 1; i <= n; i++) cout << i << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return 0;
    }
    auto cp = [&](int u, int v) -> pair<int, int> {
        return make_pair(min(u, v), max(u, v));
    };
    cout << "Second" << endl;
    vector<vector<int>> adj(n);
    vector<bool> vis(n);
    vector<vector<int>> input(n);
    map<pair<int, int>, vector<int>> edges;
    map<pair<int, int>, vector<int>> ans;
    vector<int> res(n);
    for (int i = 0; i < 2 * n; i++) {
        int x; cin >> x;
        input[x - 1].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        int u = input[i][0] % n;
        int v = input[i][1] % n;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        edges[cp(u, v)].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> comp;
        function<void(int)> dfs = [&](int src) {
            vis[src] = true;
            comp.push_back(src);
            for (int nxt: adj[src]) {
                if (vis[nxt]) continue;
                dfs(nxt);
            }
        };
        dfs(i);
        for (int j = 0; j < comp.size(); j++) {
            int u = comp[j];
            int v = comp[(j + 1) % comp.size()];
            ans[cp(u, v)].push_back(u);
        }
    }
    for (auto e: edges) {
        pair<int, int> key = e.first;
        vector<int> id = e.second;
        if (id.size() == 1) {
            if (input[id[0]][0] % n == ans[key][0]) {
                res[id[0]] = input[id[0]][0];
            } else {
                assert(ans[key][0] % n == input[id[0]][1] % n);
                res[id[0]] = input[id[0]][1];
            }
        } else {
            res[id[0]] = input[id[0]][0];
            if (input[id[1]][0] % n != input[id[0]][0] % n) {
                res[id[1]] = input[id[1]][0];
            } else {
                res[id[1]] = input[id[1]][1];
            }
        }
    }
    int sum = 0;
    for (int x: res) sum += x, sum %= (2 * n);
    if (sum % (2 * n) == 0) {
        for (int x: res) cout << x << " ";
        cout << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            if (res[i] == input[i][0]) res[i] = input[i][1];
            else res[i] = input[i][0];
        }
        for (int x: res) cout << x << " ";
        cout << '\n';
    }
}