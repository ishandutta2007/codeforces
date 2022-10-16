#include <bits/stdc++.h>
using namespace std;


const int MAX = 1e5 + 5;
const int LOG = 18;
const int INF = 1e9;
template<int MAXN, int MAXLG> struct centroidDecomp{
    vector<int> adj[MAXN];
    int sz[MAXN]; //size of subtree
    int cpar[MAXN];//parent in centroid tree
    int cdist[MAXN];
    bool vis[MAXN]; //visited array

    int L[MAXLG][MAXN]; //lca
    int depth[MAXN]; //depth
    void addEdge(int u, int v){
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    void dfs(int n, int p) {
        depth[n] = depth[p] + 1;
        L[0][n] = p;
        for (int i = 0; i < MAXLG - 1; i++)
            L[i + 1][n] = L[i][L[i][n]];
        for (int v : adj[n]) if (v != p) {
            dfs(v, n);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int i = MAXLG - 1; i >= 0; i--) {
            if (depth[u] - (1<<i) >= depth[v])
                u = L[i][u];
        }
        for (int i = MAXLG - 1; i >= 0; i--) {
            if (L[i][u] != L[i][v])
                u = L[i][u], v = L[i][v];
        }
        return u == v ? u : L[0][u];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    void dfs_sz(int n, int p=-1) {
        sz[n] = 1;
        for (int v : adj[n]) if (v != p && !vis[v]) {
            dfs_sz(v, n);
            sz[n] += sz[v];
        }
    }

    int centroid(int n) {
        dfs_sz(n);
        int num = sz[n];
        int p = -1;
        do {
            int nxt = -1;
            for (int v : adj[n]) if (!vis[v] && v != p) {
                if (2 * sz[v] > num)
                    nxt = v;
            }
            p = n, n = nxt;
        } while (~n);
        return p;
    }

    void centroid_decomp(int n, int p=-1) {
        int c = centroid(n);
        vis[c] = true;
        cpar[c] = p;
        for (int v : adj[c]) if (!vis[v]) {
            centroid_decomp(v, c);
        }
    }
};

int n, m;

centroidDecomp<MAX, LOG> cd;
int main() {
	// Finally solving the CORRECT way: centroid decomp XD
	// O(n lg^2 n) instead of O(n sqrt(n lg n))
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		cd.addEdge(u, v);
	}

	cd.dfs(0, 0);
	cd.centroid_decomp(0);
	for (int i = 0; i < n; i++)
		cd.cdist[i] = cd.dist(0, i);

	for(int i = 0; i<m; i++) {
		int t, v;
		cin >> t >> v;
		v--;
		if (t == 1) {
			for (int n = v; ~n; n = cd.cpar[n])
				cd.cdist[n] = min(cd.cdist[n], cd.dist(n, v));
		}
		else {
			int ans = cd.cdist[v];
			for (int n = v; ~n; n = cd.cpar[n])
				ans = min(ans, cd.cdist[n] + cd.dist(n, v));
			cout << ans << endl;;
		}
	}
	return 0;
}