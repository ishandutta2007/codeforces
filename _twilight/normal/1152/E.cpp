#include <bits/stdc++.h>
using namespace std;
typedef bool boolean; 

const int N = 1e5 + 5;

#define pii pair<int, int>

int n;
boolean ban[N];
int deg[N << 1];
vector<int> ans;
vector<pii> G[N << 1];
int a[N << 1], b[N], c[N];

void dfs(int p) {
	while (!G[p].empty()) {
		pii par = G[p].back();
		G[p].pop_back();
		if (!ban[par.second]) {
			ban[par.second] = true;
			dfs(par.first);
			ans.push_back(par.first);
		}
	}
}

int main() {
	scanf("%d", &n);
	int N = (n << 1) - 2;
	for (int i = 1; i < n; i++) {
		scanf("%d", b + i);
		a[i] = b[i];
	}
	for (int i = 1; i < n; i++) {
		scanf("%d", c + i);
		a[i + n - 1] = c[i];
		if (b[i] > c[i]) {
			puts("-1");
			return 0;
		}
	}
	sort(a + 1, a + N + 1);
	N = unique(a + 1, a + N + 1) - a;
	for (int i = 1; i < n; i++) {
		b[i] = lower_bound(a + 1, a + N, b[i]) - a;
		c[i] = lower_bound(a + 1, a + N, c[i]) - a;
		G[b[i]].emplace_back(c[i], i);
		G[c[i]].emplace_back(b[i], i);
		deg[b[i]]++, deg[c[i]]++;
//		cerr << b[i] << " " << c[i] << '\n';
	}
	vector<int> odd;
	for (int i = 1; i < N; i++) {
		if (deg[i] & 1) {
			odd.push_back(i);
		}
	}
	if (odd.size() > 2) {
		puts("-1");
		return 0;
	} else if (!odd.empty()) {
		dfs(odd[0]);
		ans.push_back(odd[0]);
	} else {
		dfs(1);
		ans.push_back(1);
	}
	if ((signed) ans.size() != n) {
		puts("-1");
	} else {
		reverse(ans.begin(), ans.end());
		for (auto& e : ans) {
			printf("%d ", a[e]);
		}
	}
	return 0;
}