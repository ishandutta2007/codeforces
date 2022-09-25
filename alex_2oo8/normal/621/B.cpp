#include<bits/stdc++.h>

using namespace std;

int cnt1[5000], cnt2[5000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		
		cnt1[x + y]++;
		cnt2[x - y + 1000]++;
	}
	
	long long ans = 0;
	for (int i = 0; i < 5000; i++) {
		ans += cnt1[i] * 1ll * (cnt1[i] - 1) / 2;
		ans += cnt2[i] * 1ll * (cnt2[i] - 1) / 2;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}