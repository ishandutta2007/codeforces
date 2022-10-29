#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define ll long long

int n, m, q;
int a[N];
int us[N], vs[N];
vector<int> Gi[N];
int ind[N], deg[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", us + i, vs + i);
		if (us[i] > vs[i])
			swap(us[i], vs[i]);
		Gi[us[i]].push_back(i);
		deg[us[i]]++, deg[vs[i]]++;
	}
	ll ans = 0;
#define g(x) (1ll * Gi[x].size() * (deg[x] - Gi[x].size()))
	for (int i = 1; i <= n; i++)
		ans += g(i);
	printf("%lld\n", ans);
	int u, v;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &u);
		ans -= g(u);
		for (auto e : Gi[u]) {
			v = us[e] ^ vs[e] ^ u;
			ans -= g(v);
			Gi[v].push_back(e);
			ans += g(v);
		}
		Gi[u].clear();
		printf("%lld\n", ans);
	}
	return 0;
}