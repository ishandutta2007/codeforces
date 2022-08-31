#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int w[201000];
long long Mod = 998244353;
long long F[201000], T[201000], S[201000], IF[201000];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
long long Calc(int b, int e) {
	long long t = S[e - 1];
	if (b != 1)t -= S[b - 2];
	return (t + Mod)*IF[e] % Mod;
}
int main() {
	int i;
	long long iv = Pow(100, Mod - 2);
	F[0] = 1;
	int n, Q;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		T[i] = iv * w[i] % Mod;
		F[i] = F[i - 1] * T[i] % Mod;
	}
	S[0] = F[0];
	for (i = 1; i <= n; i++)S[i] = (S[i - 1] + F[i]) % Mod;
	for (i = 0; i <= n; i++)IF[i] = Pow(F[i], Mod - 2);
	set<int>Set;
	Set.insert(1);
	Set.insert(n + 1);
	long long res = Calc(1, n);
	while (Q--) {
		int a;
		scanf("%d", &a);
		if (Set.find(a) != Set.end()) {
			auto it = Set.find(a);
			int prv = *(prev(it));
			int nxt = *(next(it));
			Set.erase(a);
			res = (res - Calc(prv, a - 1) + Mod) % Mod;
			res = (res - Calc(a, nxt - 1) + Mod) % Mod;
			res = (res + Calc(prv, nxt - 1)) % Mod;
		}
		else {
			Set.insert(a);
			auto it = Set.find(a);
			int prv = *(prev(it));
			int nxt = *(next(it));
			res = (res + Calc(prv, a - 1) + Mod) % Mod;
			res = (res + Calc(a, nxt - 1) + Mod) % Mod;
			res = (res - Calc(prv, nxt - 1) + Mod) % Mod;
		}
		printf("%lld\n", res);
	}
}