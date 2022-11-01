#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 200005;
int zhi[N], pri[N], tot, mnp[N];
inline void Init(int n = 200000) {
	zhi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!zhi[i]) pri[++tot] = i, mnp[i] = i;
		for (int j = 1; j <= tot && i * pri[j] <= n; j++) {
			zhi[i * pri[j]] = 1;
			mnp[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
		}
	}
}
int n, q, a[N], ans = 1;
map<int, int> mp[N];
multiset<int> ts[N];
inline int Get(int p) {
	if ((int)ts[p].size() != n) return 0;
	else return *ts[p].begin();
}
inline void Add(int i, int p) {
	int le = Get(p);
	int &lst = mp[i][p];
	if (lst) ts[p].erase(ts[p].find(lst));
	lst++;
	ts[p].insert(lst);
	int ce = Get(p);
	for (int j = 0; j < ce - le; j++) ans = 1ll * ans * p % mod;
}
int main() {
	Init();
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int x = a[i];
		while (x > 1) {
			Add(i, mnp[x]);
			x /= mnp[x];
		}
	}
	while (q--) {
		int i, x;
		scanf("%d%d", &i, &x);
		while (x > 1) {
			Add(i, mnp[x]);
			x /= mnp[x];
		}
		printf("%d\n", ans);
	}
	return 0;
}