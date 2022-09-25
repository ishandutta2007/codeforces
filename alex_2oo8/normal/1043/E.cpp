#include <bits/stdc++.h>

using namespace std;

const int MX = 300000;

int x[MX], y[MX];
long long ans[MX];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		ignore = scanf("%d %d", x + i, y + i);
		vec.emplace_back(x[i] - y[i], i);
	}
	
	sort(vec.begin(), vec.end());
	
	long long Xsum = 0, Ysum = accumulate(y, y + n, 0ll), L = 0, R = n;
	for (auto& p : vec) {
		int i = p.second;
		
		Ysum -= y[i];
		R -= 1;
		
		ans[i] = Xsum + y[i] * L + Ysum + x[i] * R;
		
		Xsum += x[i];
		L += 1;
	}
	
	while (m--) {
		int u, v;
		ignore = scanf("%d %d", &u, &v);
		u--; v--;
		
		int f = min(x[u] + y[v], x[v] + y[u]);
		ans[u] -= f;
		ans[v] -= f;
	}
	
	for (int i = 0; i < n; i++) printf("%lld ", ans[i]);
	printf("\n");
	
	return 0;
}