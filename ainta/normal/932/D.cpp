#include<cstdio>
#include<algorithm>
using namespace std;
long long Mx[401000][20], S[401000][20];
int Q, par[401000][20], n, p2[401000][20], Dep[401000];
int main() {
	int i, ck;
	long long a, b, last = 0;
	scanf("%d", &Q);
	n = 1;
	Dep[1] = 1;
	while (Q--) {
		scanf("%d%lld%lld", &ck, &a, &b);
		a ^= last, b ^= last;
		if (ck == 1) {
			n++;
			par[n][0] = a;
			Mx[n][0] = b;
			int x = a;
			for (i = 0; i < 19; i++) {
				par[n][i + 1] = par[par[n][i]][i];
				Mx[n][i + 1] = max(Mx[n][i], Mx[par[n][i]][i]);
			}
			int pp = a;
			for (i = 19; i >= 0; i--)if (Mx[pp][i] < b)pp = par[pp][i];
			p2[n][0] = pp;
			S[n][0] = b;
			Dep[n] = Dep[pp] + 1;
			for (i = 0; i < 19; i++) {
				p2[n][i + 1] = p2[p2[n][i]][i];
				S[n][i + 1] = S[n][i] + S[p2[n][i]][i];
			}
			continue;
		}
		int L = 0;
		int tp = a;
		for (i = 19; i >= 0; i--) {
			if (S[tp][i] <= b) {
				b -= S[tp][i];
				tp = p2[tp][i];
				L += (1 << i);
			}
		}
		L = min(L, Dep[a]);
		printf("%d\n", L);
		last = L;
	}
}