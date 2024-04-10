#include<bits/stdc++.h>

using namespace std;

const double eps = 1.0e-8;

long long cross_product(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
	return (B.first - A.first) * 1ll * (C.second - A.second) - (B.second - A.second) * 1ll * (C.first - A.first);
}

vector< pair<int, int> > v;

int main() {
	double ans = 1e9;
	int n, p, q;
	scanf("%d %d %d", &n, &p, &q);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		
		v.push_back(make_pair(x, y));
		
		ans = min(max(p * 1.0 / x, q * 1.0 / y), ans);
	}
	
	sort(v.begin(), v.end());
	
	int k = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] == v[k - 1]) continue;
		while (k > 1 && cross_product(v[k - 2], v[k - 1], v[i]) >= 0) k--;
		
		v[k++] = v[i];
		
		long long a = v[k - 1].first, b = v[k - 1].second;
		long long c = v[k - 2].first, d = v[k - 2].second;
		
		if (b * c != a * d) {
			double x = (q * c - d * p) * 1.0 / (b * c - a * d);
			double y = (p - a * x) * 1.0 / c;
			
			if (x < -eps || y < -eps) continue;
			
			ans = min(ans, x + y);
		}
	}
		
	printf("%.12f\n", ans);
	
	return 0;
}