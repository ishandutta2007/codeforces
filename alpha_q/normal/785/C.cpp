#include <bits/stdc++.h> 

using namespace std;

const long long INF = 3e9 + 1;

int main (int argc, char const *argv[]) {
	long long n, m;
	cin >> n >> m;
	if (m >= n) {
		printf("%lld\n", n);
		return 0;
	}
	long long ans = m;
	n -= m;
	long long lo = 1, hi = INF;  
	while (lo < hi) {
		long long x = lo + hi >> 1ll;
		if (x * (x + 1ll) < n + n) lo = x + 1;
		else hi = x;
	}
	printf("%lld\n", ans + lo);
  return 0;
}