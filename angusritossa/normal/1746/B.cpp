#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int a[200010];
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		int ones = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			ones += a[i];
			
		}
		int ans = 0;
		for (int i = n-1; i >= 0 && ones > 0; i--) {
			ones -= a[i];
			if (!a[i]) {
				ones--;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}