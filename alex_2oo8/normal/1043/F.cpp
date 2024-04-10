#include <bits/stdc++.h>

using namespace std;

const int MX = 300000, INF = 10;

int f[MX + 1], u[MX + 1];

bool check(int k, const int C) {
	long long res = 0;
	for (int x = 1; x * k <= MX; x++) {
		static int cnt[INF + 1];
		memset(cnt, 0, sizeof cnt);
		for (int y = x * k; y <= MX; y += x * k) {
			cnt[f[y]]++;
		}
		
		long long cur = 0;
		for (int i = 1; i <= INF; i++) {
			if (i + i <= C) cur += cnt[i] * (cnt[i] - 1ll) / 2;
			for (int j = i + 1; j <= INF && i + j <= C; j++)
				cur += cnt[i] * 1ll * cnt[j];
		}
		
		res += u[x] * cur;
	}
	
	return res > 0;
}

int main() {
	u[1] = 1;
	for (int k = 1; k <= MX; k++)
		for (int f = 2 * k; f <= MX; f += k)
			u[f] -= u[k];
	
	fill(f, f + MX + 1, INF);
	
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		f[x] = 1;
	}
	
	for (int k = MX; k > 0; k--) {
		while (check(k, f[k] - 1)) f[k]--;
	}
	
	printf("%d\n", f[1] != INF ? f[1] : -1);
	
	return 0;
}