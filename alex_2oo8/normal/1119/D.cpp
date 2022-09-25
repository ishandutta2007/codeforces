#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

long long s[MX], ans[MX];

int main() {
	int n, q;
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%lld", s + i);
	
	vector<pair<long long, int>> queries;
	ignore = scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		long long l, r;
		ignore = scanf("%lld %lld", &l, &r);
		queries.emplace_back(r - l + 1, i);
	}
	
	sort(queries.begin(), queries.end());
	sort(s, s + n);
	
	vector<long long> deltas;
	for (int i = 1; i < n; i++) deltas.push_back(s[i] - s[i - 1]);
	
	sort(deltas.begin(), deltas.end());
	
	long long sum = 0;
	size_t it = 0;
	for (auto& query : queries) {
		long long len;
		int i;
		tie(len, i) = query;
		
		while (it < deltas.size() && deltas[it] <= len) {
			sum += deltas[it];
			it++;
		}
		
		ans[i] = len * (n - it) + sum;
	}
	
	for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
	
	return 0;
}