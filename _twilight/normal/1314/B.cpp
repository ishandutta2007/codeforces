#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

int n, m, cn;
vector<int> vis;
vector<int> G[500000];

int depth(int p) {
	if (vis[p])
		return 0;
	if (!G[p].empty())
		return depth(G[p][0]) + 1;
	return 1;
}
void dfs(int p) {
	vis[p] = true;
	if (!G[p].empty())
		dfs(G[p][0]);
}
int lca(int u, int v) {
	if (vis[u] || vis[v])
		return -1;
	if (u ^ v)
		return lca(G[u][0], G[v][0]);
	return u;
}

int main() {
	scanf("%d%d", &n, &m);
	cn = 1 << n;
	int ans = 0;
	vector<int> C (cn >> 1, 0);
	while (m--) {
		int x;
		scanf("%d", &x);
		C[(x - 1) >> 1]++; 
	}
	int pcnt = cn >> 1;
	vector<int> H, L;
	for (int i = 0; i < (cn >> 2); i++)
		H.push_back(pcnt++);
	for (int i = 0; i < (cn >> 2); i++)
		L.push_back(pcnt++);
	for (int i = 0; i < (cn >> 1); i++)
		G[i] = vector<int> {H[i >> 1], L[i >> 1]};
	while (H.size() > 1u) {
		int t = H.size();
		for (int i = 0; i < t; i++) {
			int& x = L[i];
			G[x] = vector<int> {pcnt++};
			x = G[x][0];
			G[H[i]].push_back(x);
		}
		vector<int> nH (t >> 1);
		for (int i = 0; i < (t >> 1); i++)
			nH[i] = pcnt++;
		for (int i = 0; i < t; i++) {
			G[H[i]].push_back(nH[i >> 1]);
			reverse(G[H[i]].begin(), G[H[i]].end());
		}
		H = nH;
		for (int i = 0; i < (t >> 1); i++)
			nH[i] = pcnt++;
		for (int i = 0; i < t; i++)
			G[L[i]].push_back(nH[i >> 1]);
		L = nH;
	}
	G[H.back()].push_back(pcnt);
	G[L.back()].push_back(pcnt);
	L[0] = pcnt++;
	G[H.back()].push_back(pcnt);
	G[L.back()].push_back(pcnt++);
	vis.resize(pcnt, false);
	for (int i = 0; i < (cn >> 1); i++) {
		if (C[i] == 2) {
			dfs(G[i][0]);
			dfs(G[i][1]);
			ans++;
			C[i] = 0;
		}
	}
	for (int d = 1; (d << 1) < cn; d <<= 1) { 
		int d2 = d << 1;
		for (int i = 0; i < (cn >> 1); i += d2) {
			int u = -1, v = -1;
			for (int j = 0; j < d2; j++) {
				if (C[i + j]) {
					if (u == -1) {
						u = i + j;
					} else {
						v = i + j;
					}
				}
			}
			if (v != -1) {
				int g = lca(u, v);
				if (g != -1) {
					dfs(G[u][1]);
					if (depth(G[v][0]) > depth(G[v][1]))
						dfs(G[v][0]);
					else
						dfs(G[v][1]);
				} else {
					dfs(G[u][1]);
					dfs(G[v][1]);
				}
				ans += 2;
				C[u] = C[v] = 0;
			} 
		}
	}
	for (int i = 0; i < (cn >> 1); i++) {
		if (C[i]) {
			dfs(G[i][1]);
			ans++;
		}
	}
	for (auto x : vis)
		ans += x;
	printf("%d\n", ans);
	return 0;
}