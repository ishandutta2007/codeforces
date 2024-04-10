#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;

vector<int> dist(vector<vector<int>> g, int s) {
	int n = g.size();
	vector<int> dist(n, inf);
	dist[s] = 0;
	deque<int> que = {s};
	while(que.size()) {
		int v = que.front();
		que.pop_front();
		for(auto u: g[v]) {
			if(dist[v] + 1 < dist[u]) {
				dist[u] = dist[v] + 1;
				que.push_back(u);
			}
		}
	}
	return dist;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	int a[k];
	for(int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
	}
	int x[m], y[m];
	for(int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	auto A = dist(g, 0);
	auto B = dist(g, n - 1);
	int ans = A[n - 1];
	int pA[k];
	int pB[k];
	iota(pA, pA + k, 0);
	iota(pB, pB + k, 0);
	sort(pA, pA + k, [&](int x, int y) {
		return A[a[x]] > A[a[y]];
	});
	sort(pB, pB + k, [&](int x, int y) {
		return B[a[x]] < B[a[y]];
	});
	int l = 0, r = ans;
	while(r - l > 1) {
		int m = (l + r) / 2;
		int j = 0;
		int mx[2] = {-1, -1};
		bool ok = false;
		for(int i = 0; i < k; i++) {
			while(j < k && A[a[pA[j]]] + B[a[pB[i]]] + 1 > m) {
				int cand = a[pA[j]];
				if(mx[0] == -1 || B[cand] > B[mx[0]]) {
					mx[1] = mx[0];
					mx[0] = cand;
				} else if(mx[1] == -1 || B[cand] > B[mx[1]]) {
					mx[1] = cand;
				}
				j++;
			}
			int cur = a[pB[i]];
			if(mx[0] != -1 && mx[0] != cur && A[cur] + B[mx[0]] + 1 > m) {
				ok = true;
			}
			if(mx[1] != -1 && mx[1] != cur && A[cur] + B[mx[1]] + 1 > m) {
				ok = true;
			}
		}
		if(ok) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << r << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}