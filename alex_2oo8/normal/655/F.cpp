#include<bits/stdc++.h>

using namespace std;

const int MX = 1000001, md = 1000000007;

vector<int> divs[MX];
long long fact[MX], inv[MX], inv_fact[MX], coef[MX], cnt[MX];

int main() {
	fact[0] = inv_fact[0] = fact[1] = inv_fact[1] = inv[1] = 1;
	for (int i = 2; i < MX; i++) {
		fact[i] = (fact[i - 1] * i) % md;
		inv[i] = md - (md / i) * inv[md % i] % md;
		inv_fact[i] = (inv_fact[i - 1] * inv[i]) % md;
	}
	
	for (int i = 1; i < MX; i++) {
		coef[i] = (i - coef[i] + md) % md;
		divs[i].push_back(i);
		for (int j = 2 * i; j < MX; j += i) {
			divs[j].push_back(i);
			coef[j] += coef[i];
			if (coef[j] >= md) coef[j] -= md;
		}
	}
	
	int n, k, q, ans = 0;
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 0; i < n + q; i++) {
		int x;
		scanf("%d", &x);
		
		for (int d : divs[x]) {
			int p = cnt[d];
			if (p >= k) {
				ans -= ((fact[p] * inv_fact[p - k] % md) * inv_fact[k] % md) * coef[d] % md;
				if (ans < 0) ans += md;
			}
			
			cnt[d]++;
			p = cnt[d];
			if (p >= k) {
				ans += ((fact[p] * inv_fact[p - k] % md) * inv_fact[k] % md) * coef[d] % md;
				if (ans >= md) ans -= md;
			}
		}
		
		if (i >= n) printf("%d\n", ans);
	}
	
	return 0;
}