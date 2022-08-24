#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>G[3010];
int n, m, U[3010];
long long res = 1e18;
int main() {
	int i, a, b, j, k;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
	}
	for (i = 1; i <= m; i++) {
		if (!G[i].empty())sort(G[i].begin(), G[i].end());
	}
	for (i = 0; i <= n - G[1].size(); i++) {
		int M = i + G[1].size();
		if (!M)continue;
		int cur = G[1].size(), cnt = 0;
		long long s = 0;
		for (j = 2; j <= m; j++) {
			int sz = G[j].size();
			for (k = 0; k <= sz - M; k++) {
				cur++;
				s += G[j][k];
			}
			for (k = max(sz - M + 1, 0); k < sz; k++) {
				U[cnt++] = G[j][k];
			}
		}
		sort(U, U + cnt);
		int pv = 0;
		while (cur < M) {
			cur++;
			s += U[pv++];
		}
		res = min(res, s);
	}
	printf("%lld\n", res);
}