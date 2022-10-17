#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.first << ", " << p.second << ")";
}
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> sub(n);
        vector<int> centroids;
        function<void(int, int)> dfs_sub = [&](int src, int par) {
            sub[src] = 1;
            vector<int> subs;
            for (int nxt: adj[src]) {
                if (nxt == par) continue;
                dfs_sub(nxt, src);
                sub[src] += sub[nxt];
                subs.push_back(sub[nxt]);
            }
            subs.push_back(n - sub[src]);
            sort(subs.begin(), subs.end());
            if (subs.back() <= n / 2) {
                centroids.push_back(src);
            }
        };
        dfs_sub(0, -1);
        if (centroids.size() == 1) {
            cout << 1 << " " << adj[0][0] + 1 << '\n';
            cout << 1 << " " << adj[0][0] + 1 << '\n';
            continue;
        }
        int c1 = centroids[0];
        int c2 = centroids[1];
        pair<int, int> leaf;
        function<void(int, int)> find_leaf = [&](int src, int par) {
            for (int nxt: adj[src]) {
                if (nxt == par) continue;
                find_leaf(nxt, src);
            }
            if (adj[src].size() == 1) {
                leaf = {src, par};
            }
        };
        find_leaf(c1, c2);
        cout << leaf.first + 1 << " " << leaf.second + 1 << '\n';
        cout << leaf.first + 1 << " " << c2 + 1 << '\n';
    }
    return 0;
}