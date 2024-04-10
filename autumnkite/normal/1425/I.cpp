#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 
 
#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> fa(n, -1);
	std::vector<std::vector<int>> E(n);
	for (int i = 1; i < n; ++i) {
		std::cin >> fa[i];
		--fa[i];
		E[fa[i]].push_back(i);
	}

	int idx = 0;
	std::vector<int> dfn(n), end(n), dep(n), da(n), dt(n), dd(n);
	std::function<void(int)> dfs = [&](int u) {
		da[idx] = a[u], dt[idx] = 0, dd[idx] = dep[u];
		dfn[u] = idx++;
		for (int v : E[u]) {
			dep[v] = dep[u] + 1;
			dfs(v);
		}
		end[u] = idx;
	};
	dep[0] = 0, dfs(0);

	for (int k = 0; k < q; ++k) {
		int x;
		std::cin >> x;
		--x;
		int l = dfn[x], r = end[x];
		int ans = 0, cnt = 0;
		for (int i = l; i < r; ++i) {
			if (dt[i] <= k) {
				dt[i] = k + da[i];
				ans += dd[i];
				++cnt;
			}
		}
		std::cout << ans - cnt * dep[x] << " " << cnt << "\n";
	}
}