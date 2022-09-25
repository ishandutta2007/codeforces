#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	map<int, int> cnt1;
	map<pair<int, int>, int> cnt2;
	
	for (int i = 0, a, b; i < n; i++) {
		ignore = scanf("%d %d", &a, &b);
		
		cnt1[a]++;
		if (a != b) cnt1[b]++;
		
		cnt2[make_pair(min(a, b), max(a, b))]++;
	}
	
	long long ans = 0;
	for (auto& p : cnt1) {
		ans += p.second * (p.second - 1LL) / 2;
	}
	
	for (auto& p : cnt2) {
		if (p.first.first != p.first.second) {
			ans -= p.second * (p.second - 1LL) / 2;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}