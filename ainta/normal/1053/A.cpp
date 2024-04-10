#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n, m, K;
vector<long long>d1, d2;
int main() {
	scanf("%lld%lld%lld", &n, &m, &K);
	long long t = (n*m*2)%K;
	if (t == 0) {
		long long M = n*m*2 / K;
		for (long long i = 1; i*i <= n; i++) {
			if (n%i == 0)d1.push_back(i), d1.push_back(n/i);
		}
		for (long long i = 1; i*i <= m; i++) {
			if (m%i == 0)d2.push_back(i), d2.push_back(m / i);
		}
		long long Mx = 0;
		for (auto &x : d1)for (auto &y : d2) {
			long long t = x*y;
			if (t <= n && M%t == 0)Mx = max(Mx, t);
			t *= 2;
			if (t <= n && M%t == 0)Mx = max(Mx, t);
		}
		if (Mx == 0 || M / Mx > m)printf("NO\n");
		else {
			printf("YES\n");
			printf("%lld %lld\n", 0ll, 0ll);
			printf("%lld %lld\n", Mx, 0ll);
			printf("%lld %lld\n", 0ll, M/Mx);
		}
		return 0;
	}
	puts("NO");

}