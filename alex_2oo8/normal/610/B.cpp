#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

int a[MX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	
	int mn = a[0];
	for (int i = 0; i < n; i++) mn = min(a[i], mn);
	
	long long ans = mn * 1ll * n;
	int cur = 0, mx = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++) {
			if (a[j] == mn) {
				mx = max(cur, mx);
				cur = 0;
			}
			else cur++;
		}
	
	printf("%lld\n", ans + mx);
	
	return 0;
}