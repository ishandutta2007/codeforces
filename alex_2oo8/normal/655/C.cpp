#include<bits/stdc++.h>

using namespace std;

char s[100002];
int sum[100001];

int main() {
	int n, k;
	scanf("%d %d %s", &n, &k, s + 1);
	
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + (s[i] == '0');
	}
	
	int ans = n;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') continue;
		
		int d = 0;
		for (int f = (1 << 16); f > 0; f /= 2)
			if (sum[min(i + d + f - 1, n)] - sum[max(i - d - f, 0)] < k + 1) {
				d += f;
			}
		
		ans = min(ans, d);
	}
	
	printf("%d\n", ans);
	
	return 0;
}