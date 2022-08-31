#include <iostream>
#include <vector>
#include <map>

#define LOG 18

std::vector<std::vector<int> > Adj;
std::vector<std::vector<std::pair<int, int> > > far;
std::map<std::pair<int, int>, int> rev;
std::vector<std::vector<int> > par;
std::vector<int> depth, vis, good;

void initLca(int u, int p) {
	par[0][u] = p;
	depth[u] = p == -1 ? 0 : depth[p]+1;

	for(int i = 1; i < LOG; i++) {
		if(par[i-1][u] == -1)
			par[i][u] = -1;
		else
			par[i][u] = par[i-1][par[i-1][u]];
	}
	
	for(int v : Adj[u])
		if(v != p)
			initLca(v, u);
}

// Returns kth ancestor of u, -1 if doesn't exist
int kthAnc(int u, int k) {
	if(depth[u] < k)
		return -1;

	for(int i = LOG-1; i >= 0; i--) {
		if((1 << i) <= k) {
			u = par[i][u];
			k -= (1 << i);
		}
	}
	
	return u;
}

// Returns least common ancestor of u and v
int lca(int u, int v) {
	if(depth[u] < depth[v])
		u ^= v ^= u ^= v;

	u = kthAnc(u, depth[u]-depth[v]);

	if(u == v)
		return u;

	for(int i = LOG-1; i >= 0; i--) {
		if(par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}

	return par[0][u];
}

// Root the tree at r and find kth ancestor of u
int kthWithRootR(int u, int k, int r) {
	int l = lca(u, r);
	if(depth[u] - depth[l] >= k)
		return kthAnc(u, k);
	else
		return kthAnc(r, depth[u] + depth[r] - 2*depth[l] - k);
}

// Returns a pair {a, b} such that length of path i -> b is a, 
// where v doesn't lie on this path and a is maximum possible.
// Here v is a neighbor of i for which Adj[v][j] = i
std::pair<int, int> findFar(int i, int j) {
	if(far[i][j].first != -1)
		return far[i][j];

	far[i][j].first = 0; far[i][j].second = i;
	for(int v : Adj[i]) {
		if(v == Adj[i][j])
			continue;

		std::pair<int, int> next = findFar(v, rev[{v, i}]);

		if(next.first + 1 > far[i][j].first) {
			far[i][j].first = next.first + 1;
			far[i][j].second = next.second;
		}
	}

	return far[i][j];
}

// Returns second vertex on the path from u to v
// Make sure u != v
int findDir(int u, int v) {
	if(lca(u, v) != u)
		return par[0][u];

	return kthAnc(v, depth[v]-depth[u]-1);
}

int dist(int a, int b) {
	return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

bool onPath(int a, int b, int x) {
	return dist(a, x) + dist(b, x) == dist(a, b);
}

void dfs(int u, int p) {
	vis[u] = true;
	for(int v : Adj[u])
		if(v != p)
			dfs(v, u);
}

int main() {
	int t;
	std::cin >> t;

	while(t--) {
		int n, a, b;
		std::cin >> n >> a >> b;
		a--; b--;

		Adj = std::vector<std::vector<int> >(n);
		far = std::vector<std::vector<std::pair<int, int> > >(n);
		par = std::vector<std::vector<int> >(LOG, std::vector<int>(n));
		depth = vis = good = std::vector<int>(n, 0);
		rev.clear();

		for(int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			u--; v--;
			rev[{u, v}] = Adj[u].size();
			rev[{v, u}] = Adj[v].size();
			Adj[u].push_back(v);
			Adj[v].push_back(u);
			far[u].push_back({-1, -1});
			far[v].push_back({-1, -1});
		}

		initLca(0, -1);
		int len = depth[a] + depth[b] - 2*depth[lca(a, b)];
		
		int la = -1, lb = -1;
		int fa = -1, fb = -1;
		
		int it = 0;
		while(true) {
			if(it%2) {
				int c = findDir(a, b);
				std::pair<int, int> next = findFar(a, rev[{a, c}]);
				
				if(la == next.second)
					break;

				la = a = next.second;
				b = fb = kthWithRootR(a, len, b);
			}
			else {
				int c = findDir(b, a);
				std::pair<int, int> next = findFar(b, rev[{b, c}]);
				
				if(lb == next.second)
					break;
				
				lb = b = next.second;
				a = fa = kthWithRootR(b, len, a);
			}
			it++;
		}
		
		int all = false;
		if(fa == b || !onPath(a, b, fa) || fb == a || !onPath(a, b, fb))
			all = true;
		
		if(!all) {
			dfs(fa, findDir(fa, b));
			dfs(fb, findDir(fb, a));
		}

		bool poss = false;
		for(int i = 0; i < n; i++) {
			if(!all && !vis[i])
				continue;

			int c = 0;
			for(int v : Adj[i])
				if(findFar(v, rev[{v, i}]).first+1 >= len) c++;

			if(c >= 3)
				poss = true;
		}
		
		if(poss)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}