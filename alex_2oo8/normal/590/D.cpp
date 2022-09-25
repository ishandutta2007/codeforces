#include<bits/stdc++.h>

using namespace std;

int q[150], l[151][150 * 150], r[151][150 * 150];

int main() {
	int n, k, s;
	scanf("%d %d %d", &n, &k, &s);
	
	for (int i = 0; i < n; i++) scanf("%d", q + i);
	
	int m = min(k, n - k), maxS = 0;
	for (int i = 0; i < k; i++) {
		int dist = k - i, qq = q[i];
		maxS += dist;
		for (int cnt = min(i + 1, m); cnt > 0; cnt--)
			for (int sum = dist; sum <= maxS; sum++)
				l[cnt][sum] = max(l[cnt][sum], l[cnt - 1][sum - dist] + qq);
	}
	
	for (int i = 0; i <= m; i++)
		for (int j = 0; j < 150 * 150; j++)
			r[i][j] = (int)(1e9);
	
	r[0][0] = 0;
	maxS = 0;
	for (int i = k; i < n; i++) {
		int dist = i - k, qq = q[i];
		maxS += dist;
		for (int cnt = min(i - k + 1, m); cnt > 0; cnt--)
			for (int sum = dist; sum <= maxS; sum++)
				r[cnt][sum] = min(r[cnt][sum], r[cnt - 1][sum - dist] + qq);
	}
	
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < 150 * 150; j++) {
			l[i][j] = max(l[i][j], l[i][j - 1]);
			r[i][j] = min(r[i][j], r[i][j - 1]);
		}
		
		for (int j = 0; j < min(150 * 150, s + 1); j++) ans = min(ans, r[i][j] - l[i][min(s - j, 150 * 150 - 1)]);
	}
	
	for (int i = 0; i < k; i++) ans += q[i];
	
	printf("%d\n", ans);
	
	return 0;
}