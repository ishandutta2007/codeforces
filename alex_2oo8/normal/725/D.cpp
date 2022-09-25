#include <bits/stdc++.h>

using namespace std;

const int MX = 300000;

int main() {
	int n;
	long long T, W;
	scanf("%d %lld %lld", &n, &T, &W);
	
	vector<pair<long long, long long>> v;
	for (int i = 1; i < n; i++) {
		long long t, w;
		scanf("%lld %lld", &t, &w);
		
		v.emplace_back(t, w);
	}
	
	sort(v.begin(), v.end());
	
	multiset<long long> s;
	
	int ans = n, i = n - 2;
	while (true) {
		while (i >= 0 && v[i].first > T) {
			s.insert(v[i].second + 1 - v[i].first);
			i--;
		}
		
		ans = min(ans, (int)s.size() + 1);
		
		if (s.size() == 0 || T < *s.begin()) break;
		
		T -= *s.begin();
		s.erase(s.begin());
	}
	
	printf("%d\n", ans);
	
	return 0;
}