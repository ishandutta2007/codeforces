#include<bits/stdc++.h>

using namespace std;

const int MX = 300000;

int t[MX];

int main() {
	int n, k, b, c;
	scanf("%d %d %d %d", &n, &k, &b, &c);
	for (int i = 0; i < n; i++) scanf("%d", t + i);
	
	if (b > 5 * c) b = 5 * c;
	
	sort(t, t + n);
	
	long long ans = (long long)(1e+18);
	for (int r = 0; r < 5; r++) {
		long long sum = 0, offset = 0, last = 0;
		multiset<long long> S;
		for (int i = 0; i < n; i++) {
			int x = t[i];
			while ((x - r) % 5 != 0) x++;
			
			sum += (x - last) / 5 * 1ll * b * 1ll * S.size();
			offset += (x - last) / 5;
			last = x;
			
			int cost = (x - t[i]) * c;
			
			sum += cost;
			S.insert(cost - offset * b);
			
			if (S.size() > k) {
				long long f = *S.rbegin();
				S.erase(S.find(f));
				sum -= f + offset * b;
			}
			
			if (S.size() == k) ans = min(ans, sum);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}