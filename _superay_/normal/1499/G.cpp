#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
const int mod = 998244353;
int n1, n2, m, match[N], pw2[N], deg[N], curans;
vector<int> va;
set<int> st;
struct Dat {
	vector<int> vec;
	int sum;
	inline Dat() { sum = 0; }
	inline void Ins(int x) {
		vec.push_back(x);
		sum = (sum + pw2[x]) % mod;
	}
	inline void Swap(Dat &oth) {
		vec.swap(oth.vec);
		swap(sum, oth.sum);
	}
	inline void Clear() {
		vector<int>().swap(vec);
		sum = 0;
	}
	inline void Merge(Dat &oth) {
		if (vec.size() < oth.vec.size()) Swap(oth);
		for (int t : oth.vec) vec.push_back(t);
		sum = (sum + oth.sum) % mod;
		oth.Clear();
	}
} d[N][2];
inline void Norm(int x) {
	if (st.count(x)) return;
	int y = match[x];
	st.erase(y);
	st.insert(x);
	if ((x <= n1) == (y <= n1)) {
		curans = (curans - d[y][0].sum + mod) % mod;
		d[x][0].Swap(d[y][1]);
		d[x][1].Swap(d[y][0]);
		curans = (curans + d[x][0].sum) % mod;
	} else {
		d[x][0].Swap(d[y][0]);
		d[x][1].Swap(d[y][1]);
	}
}
inline void Ae(int x, int y, int id) {
	if (deg[x] % 2 == 0 && deg[y] % 2 == 0) {
		d[x][0].Ins(id);
		match[y] = x;
		match[x] = y;
		st.insert(x);
		curans = (curans + d[x][0].sum) % mod;
	} else if (deg[x] % 2 == 1 && deg[y] % 2 == 0) {
		Norm(x);
		st.erase(x);
		st.insert(y);
		match[y] = match[x];
		match[match[x]] = y;
		curans = (curans - d[x][0].sum + mod) % mod;
		d[y][0].Swap(d[x][1]);
		d[y][1].Swap(d[x][0]);
		d[y][0].Ins(id);
		curans = (curans + d[y][0].sum) % mod;
	} else if (deg[x] % 2 == 0 && deg[y] % 2 == 1) {
		Norm(y);
		st.erase(y);
		st.insert(x);
		match[x] = match[y];
		match[match[y]] = x;
		curans = (curans - d[y][0].sum + mod) % mod;
		d[x][0].Swap(d[y][1]);
		d[x][1].Swap(d[y][0]);
		d[x][0].Ins(id);
		curans = (curans + d[x][0].sum) % mod;
	} else {
		if (match[x] == y) {
			if (st.count(y)) swap(x, y);
			st.erase(x);
			match[x] = match[y] = 0;
			for (int t : d[x][0].vec) va.push_back(t);
			d[x][0].Clear();
			d[x][1].Clear();
		} else {
			Norm(x);
			Norm(y);
			st.erase(x);
			st.erase(y);
			st.insert(match[x]);
			match[match[x]] = match[y];
			match[match[y]] = match[x];
			d[x][0].Merge(d[y][0]);
			d[x][1].Merge(d[y][1]);
			d[x][1].Ins(id);
			if ((x <= n1) == (match[x] <= n1)) {
				curans = (curans - d[x][0].sum + mod) % mod;
				d[match[x]][0].Swap(d[x][1]);
				d[match[x]][1].Swap(d[x][0]);
				curans = (curans + d[match[x]][0].sum) % mod;
			} else {
				d[match[x]][0].Swap(d[x][0]);
				d[match[x]][1].Swap(d[x][1]);
			}
		}
	}
	deg[x]++, deg[y]++;
}
int eu[N], ev[N];
int main() {
	for (int i = pw2[0] = 1; i < N; i++) pw2[i] = 2 * pw2[i - 1] % mod;
	scanf("%d%d%d", &n1, &n2, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		y += n1;
		eu[i] = x, ev[i] = y;
		Ae(x, y, i);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int t, x, y;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &x, &y);
			y += n1;
			++m;
			eu[m] = x, ev[m] = y;
			Ae(x, y, m);
			printf("%d\n", curans);
			fflush(stdout);
		} else {
			vector<int> ans = va;
			for (int x : st) {
				for (int u : d[x][0].vec) ans.push_back(u);
			}
			printf("%d", (int)ans.size());
			for (int &x : ans) printf(" %d", x);
			printf("\n");
			fflush(stdout);
		}
	}
	return 0;
}