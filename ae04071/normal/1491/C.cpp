#include <bits/stdc++.h>
using namespace std;

int n,s[5001];
long long cnt[5001];

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		long long ans = 0, sum = 0;
		scanf("%d",&n);

		for(int i=0;i<=n;i++) cnt[i] = 0;
		
		for(int i=0;i<n;i++) {
			scanf("%d", s+i);

			ans += max(0ll, s[i] - 1 - cnt[i]);
			long long c = max(cnt[i], s[i]-1ll);
			if (c) {
				for(int j=i+2;j<=min(n-1, i+s[i]);j++) cnt[j]++;
				c -= s[i]-1;
				cnt[i+1] += c;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}