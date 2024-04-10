#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5, V = 1e7 + 1;

int n, K, m;
int a[N];

int pri[V], mp[V], mu[V];

void Euler(int n) {
	static bitset<V> vis;
	int num = 0;
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis.test(i)) {
			pri[num++] = i;
			mp[i] = i;
			mu[i] = -1;
		}
		for (int* p = pri, *_ = pri + num, x; p != _ && (x = *p * i) <= n; p++) {
			vis.set(x);
			mp[x] = *p;
			if (i % *p) {
				mu[x] = -mu[i];
			} else {
				mu[x] = 0;
				break;
			}
		}
	}
}

vector<int> factor(int x) {
	vector<int> P;
	while (x > 1) {
		P.push_back(mp[x]);
		while (!(x % P.back()))
			x /= P.back();
	}
	return P;
}
vector<int> Ps(vector<int> P) {
	vector<int> rt;
	int n = P.size();
	for (int s = 0; s < (1 << n); s++) {
		int prod = 1;
		for (int j = 0; j < s && (s >> j); j++) {
			if ((s >> j) & 1) {
				prod *= P[j];
			}
		}
		rt.push_back(prod);
	}	
	return rt;
}

int cnt[V];
vector<int> P[N];

void add(vector<int>& P) {
	for (auto idx : P)
		cnt[idx] += mu[idx];
}
void clear(vector<int>& P) {
	for (auto idx : P)
		cnt[idx] = 0;
}
int query(vector<int>& P) {
	int rt = 0;
	for (auto idx : P)
		rt += cnt[idx];
	return rt;
}

vector<int> cli, ncli;

void add(int l, int r) {
	for (int i = l; i <= r; i++) {
		add(P[cli[i]]);
	}
}
void clear(int l, int r) {
	for (int i = l; i <= r; i++) {
		clear(P[cli[i]]);
	}
}

int cost[N];
boolean in_cli[N];
vector<int> adj[N];
vector<int> L1, L2;

void dividing(int l, int r, vector<int> S) {
	if (l == r) {
		adj[cli[l]] = S;
		for (auto x : S)
			adj[x].push_back(cli[l]);
		return;
	}
	int mid = (l + r) >> 1;
	add(l, mid);
	vector<int> vL, vR;
	for (auto x : S) {
		if (query(P[x])) {
			vL.push_back(x);	
		} else {
			vR.push_back(x);
		}
	}
	clear(l, mid);
	(vector<int>()).swap(S);
	dividing(l, mid, vL);
	dividing(mid + 1, r, vR);
}

int sx, sy;
boolean get(int l, int r, int x) {
	add(l, r);
	if (!query(P[x])) {
		clear(l, r);
		return false;
	}
	clear(l, r);
	int mid;
	while (l < r) {
		mid = (l + r) >> 1;
		for (int i = l; i <= mid; i++) {
			add(P[cli[i]]);
		}
		boolean flag = query(P[x]);
		for (int i = l; i <= mid; i++) {
			clear(P[cli[i]]);
		}
		if (flag) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	sx = cli[l];
	sy = x;
	return true;
}

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		m = max(m, a[i]);
	}
	Euler(m);
	for (int i = 1; i <= n && (signed) cli.size() < K; i++) {
		P[i] = Ps(factor(a[i]));
		if ((in_cli[i] = !query(P[i]))) {
			add(P[i]);
			cli.push_back(i);
		} else {
			ncli.push_back(i);
		}
	}
	if ((signed) cli.size() == K) {
		for (auto x : cli) {
			printf("%d ", x);
		}
		return 0;
	}
	for (auto x : cli) {
		clear(P[x]);
	}
	dividing(0, (signed) cli.size() - 1, ncli);
	for (auto x : ncli) {
		cost[x] = 2;
		L2.push_back(x);
	}
	vector<int> ans;
	if ((K & 1)) {
		boolean suc = false;
		int s = (signed) cli.size();
		for (auto x : cli) {
			if (adj[x].size() > 1) {
				suc = true;
				int y = adj[x][0], z = adj[x][1];
				cost[y] = -1, cost[z] = -1;
				ans = {x, y, z};
				for (auto p : adj[x]) {
					if (cost[p] == 2) {
						cost[p] = 1;
						L1.push_back(p);
					}
				}
			}
		}
		if (!suc) {
			add(0, s - 1);
			for (auto x : ncli) {
				if (query(P[x]) > 1) {
					clear(0, s - 1);
					int y = adj[x][0], idx = 0;
					while (cli[idx] ^ y)
						idx++;
					if (idx) {
						suc = get(0, idx - 1, x);
					}
					if (idx < s - 1 && !suc) {
						suc = get(idx + 1, s - 1, x);
					}
					break;
				}
			}
			assert(suc);	
			cost[sy] = -1;
			ans = {sx, sy, adj[sy][0]};
			for (auto z : adj[sx]) {
				if (cost[z] == 2) {
					cost[z] = 1;
					L1.push_back(z);
				}
			}
			for (auto z : adj[adj[sy][0]]) {
				if (cost[z] == 2) {
					cost[z] = 1;
					L1.push_back(z);
				}
			}
		}
		K -= 3;
	}
	while (!L2.empty() && K >= 2) {
		int x = L2.back();
		L2.pop_back();
		if (cost[x] < 2)
			continue;
		K -= 2;
		int y = adj[x][0];
		ans.push_back(x);
		ans.push_back(y);
		for (auto z : adj[y]) {
			cost[z] = 1;
			if (z != x) {
				L1.push_back(z);
			}
		}
	}
	while (!L1.empty() && K) {
		ans.push_back(L1.back());
		L1.pop_back();
		K--;
	}
	assert(!K);
	for (auto x : ans) {
		printf("%d ", x);
	}
	return 0;
}