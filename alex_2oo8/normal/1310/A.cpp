#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) ignore = scanf("%d", &vec[i].first);
	for (int i = 0; i < n; i++) ignore = scanf("%d", &vec[i].second);
	
	sort(vec.begin(), vec.end());
	
	multiset<pair<int, int>> active;
	int x = 0, i = 0;
	long long ans = 0;
	while (i < n || active.empty() == false) {
		while (i < n && vec[i].first <= x) {
			active.emplace(-1 * vec[i].second, vec[i].first);
			i++;
		}
		
		if (active.empty()) {
			x = vec[i].first;
			continue;
		}
		
		auto p = *active.begin();
		active.erase(active.begin());
		
		ans -= (x - p.second) * 1LL * p.first;
		
		x++;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}