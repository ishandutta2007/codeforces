#include <bits/stdc++.h>

using namespace std;

const int MX = 100;

int x[MX], y[MX];

int f(int i, int z) {
	return (x[i] < z && z < y[i]) ? 0 : 1;
}

bool used[2 * MX];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		int n, k;
		ignore = scanf("%d %d", &n, &k);
		
		fill(used, used + 2 * n, false);
		
		for (int i = 0; i < k; i++) {
			ignore = scanf("%d %d", x + i, y + i);
			
			x[i]--;
			y[i]--;
			
			if (x[i] > y[i]) swap(x[i], y[i]);
			
			used[x[i]] = used[y[i]] = true;
		}
		
		int ans = (n - k) * (n - k - 1) / 2;
		for (int i = 0; i < k; i++) {
			int cnt[2] = {0, 0};
			for (int j = 0; j < 2 * n; j++) {
				if (used[j] == false) {
					cnt[f(i, j)]++;
				}
			}
			
			ans += min(cnt[0], cnt[1]);
			
			for (int j = 0; j < i; j++) {
				if (f(i, x[j]) != f(i, y[j])) ans++;
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}