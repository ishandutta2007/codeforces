#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll sqr(int x) {
	return (ll)x * x;
}

inline ll calc(int x, int y, int z) {
	return sqr(x - y) + sqr(y - z) + sqr(z - x);
}

ll solve() {
	vector <int> n(3);
	for (int i = 0; i < 3; i++)
		scanf("%d", &n[i]);
	vector <vector <int>> v(3);
	for (int i = 0; i < 3; i++) {
		v[i].resize(n[i]);
		for (int j = 0; j < n[i]; j++)
			scanf("%d", &v[i][j]);
		sort(v[i].begin(), v[i].end());
	}
	sort(v.begin(), v.end());
	
	ll sol = 2e18;
	do 
		for (auto it : v[0]) {
			auto it1 = lower_bound(v[1].begin(), v[1].end(), it);
			auto it2 = upper_bound(v[2].begin(), v[2].end(), it);
			if (it1 != v[1].end() && it2 != v[2].begin())
				sol = min(sol, calc(it, *it1, *(--it2)));
		}
	while (next_permutation(v.begin(), v.end()));
	
	return sol;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)
		printf("%lld\n", solve());
	return 0;
}