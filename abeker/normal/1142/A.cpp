#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int N, K, A, B;
vector <pii> fact_n, fact_k;

vector <pii> factorize(int x) {
	vector <pii> fact;
	for (int i = 2; i * i <= x; i++) {
		if (x % i)
			continue;
		int ex = 0;
		for (; !(x % i); x /= i)
			ex++;
		fact.push_back({i, ex});
	}
	if (x > 1)
		fact.push_back({x, 1});
	return fact;
}

ll get(int x) {
	ll res = x;
	for (auto it : fact_n)
		if (K % it.first) 
			for (int i = 0; i < it.second; i++)
				res *= it.first;
	for (auto it : fact_k) {
		int pot = 1;
		for (int i = 0; i < it.second; i++) 
			pot *= it.first;
		if (x % pot)
			continue;
		for (int t = N; !(t % it.first); t /= it.first)
			res *= it.first;
	}
	return res;
}

int main() {
	scanf("%d%d%d%d", &N, &K, &A, &B);
	
	fact_n = factorize(N);
	fact_k = factorize(K);
	
	ll max_gcd = 1, min_gcd = 1e18;
	for (int i = -1; i < 2; i += 2)
		for (int j = -1; j < 2; j += 2) {
			int tmp = __gcd((i * A + j * B + 2 * K) % K, K);
			max_gcd = max(max_gcd, get(tmp));
			min_gcd = min(min_gcd, (ll)tmp);
		}
	
	printf("%lld %lld\n", (ll)N * K / max_gcd, (ll)N * K / min_gcd);
	
	return 0;
}