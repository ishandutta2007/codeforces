#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	set<long long> ans;
	
	auto foo = [&](int d) {
		int cnt = n / d;
		ans.insert(cnt * (cnt - 1ll) / 2 * d + cnt);
	};
	
	for (int d = 1; d * d <= n; d++)
		if (n % d == 0) {
			foo(d);
			foo(n / d);
		}
	
	for (auto x : ans) printf("%lld ", x);
	printf("\n");
	
	return 0;
}