#include <bits/stdc++.h>
using namespace std;

void mul(int &x, int y) {
	x = (long long)x * y % 998244353;
}

int main() {
	int N;
	scanf("%d", &N);
	vector <int> deg(N + 1);
	int ans = N;
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		mul(ans, ++deg[u]);
		mul(ans, ++deg[v]);
	}
	printf("%d\n", ans);
	return 0;
}