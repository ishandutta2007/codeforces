#include <bits/stdc++.h>
typedef long long LL;
const int N = 100000;
int T; LL p, q;
int pr[N], check[N+5];
void sieve() {
	check[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!check[i]) pr[++pr[0]] = i;
		for (int j = 1; j <= pr[0] && i*pr[j] <= N; j++) {
			check[i*pr[j]] = 1;
			if (!(i % pr[j])) break;
		}
	}
}
int main() {
	sieve();
	for (scanf("%d", &T); T; T--) {
		scanf("%lld%lld", &p, &q);
		if (p % q) printf("%lld\n", p);
		else {
			LL ans = 0;
			std::vector<int> fac;
			for (int i = 2; i <= sqrt(q); i++) {
				if (check[i]) continue;
				while (!(q % i)) fac.push_back(i), q /= i;
			}
			if (q != 1) fac.push_back(q);
			for (int i = 0, r = 0; i < fac.size(); i = r) {
				while (r < fac.size() && fac[i] == fac[r]) r++;
				int t = 0; LL tmp = 1, _p = p;
				while (!(p % tmp)) t++, tmp *= fac[i];
				for (int j = t; j > r-i; j--) _p /= fac[i];
				ans = std::max(ans, _p);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}