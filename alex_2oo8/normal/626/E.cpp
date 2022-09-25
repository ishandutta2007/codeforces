#include<bits/stdc++.h>

using namespace std;

const int MX = 200001;

int x[MX], n, bestI = 1, bestOffset = 0;
long long s[MX], bestP = 0, bestQ = 1;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", x + i);
	
	sort(x + 1, x + n + 1);
	
	s[0] = 0;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + x[i];
	
	for (int i = 1; i <= n; i++) {
		int offset = 0;
		for (int k = (1 << 20); k > 0; k /= 2)
			if (i - offset - k > 0 && n - i >= offset + k && (x[i - offset - k] + x[n + 1 - offset - k]) * (2ll * (offset + k) + 1) > 2 * (s[i] - s[i - offset - k - 1] + s[n] - s[n - offset - k]))
				offset += k;
		
		long long Q = 2 * offset + 1;
		long long P = s[i] - s[i - offset - 1] + s[n] - s[n - offset] - x[i] * Q;
		
		if (P * bestQ > bestP * Q) {
			bestP = P;
			bestQ = Q;
			
			bestI = i;
			bestOffset = offset;
		}
	}
	
	printf("%d\n", 2 * bestOffset + 1);
	for (int i = bestI - bestOffset; i <= bestI; i++) printf("%d ", x[i]);
	for (int i = n - bestOffset + 1; i <= n; i++) printf("%d ", x[i]);
	printf("\n");
	
	return 0;
}