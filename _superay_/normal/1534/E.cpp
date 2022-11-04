#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, k, dist[N], fr[N], lab[N];
int main() {
	scanf("%d%d", &n, &k);
	memset(dist, -1, sizeof(dist));
	queue<int> que;
	dist[0] = 0;
	que.push(0);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = 0; i <= u; i++) if (k - i <= n - u) {
			int v = u - i + k - i;
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				fr[v] = k - i;
				que.push(v);
			}
		}
	}
	if (dist[n] == -1) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) lab[i] = 1;
	int ans, tmp;
	ans = 0;
	for (int u = n; u; ) {
		vector<int> v1, v0, qr;
		for (int i = 1; i <= n; i++) if (lab[i]) v1.push_back(i); else v0.push_back(i);
		for (int i = 0; i < fr[u]; i++) qr.push_back(v1[i]);
		for (int i = 0; i < k - fr[u]; i++) qr.push_back(v0[i]);
		printf("?");
		for (int i = 0; i < k; i++) printf(" %d", qr[i]), lab[qr[i]] ^= 1;
		printf("\n");
		fflush(stdout);
		scanf("%d", &tmp);
		ans ^= tmp;
		u = 0;
		for (int i = 1; i <= n; i++) if (lab[i]) u++;
	}
	printf("! %d\n", ans);
	return 0;
}