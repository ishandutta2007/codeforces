#include <bits/stdc++.h>
#define P 998244353
#define M 1000010

using namespace std;

typedef long long ll;

int n;

int Head[M], Next[M], Go[M], Deg[M];

ll Fac[M], Rev[M], Cnt = 0;

ll F[M];

void addedge(int x, int y) {
	Go[++Cnt] = y;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
}

void DFS(int x, int f = 0) {
	for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) DFS(Go[T], x);
	int deg = Deg[x] - (x != 1);
	ll ans = 1;
	for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) ans = ans * F[Go[T]] % P;
	ans = ans * Fac[deg] % P;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) Fac[i] = !i ? 1 : Fac[i - 1] * i % P;
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b);
		addedge(b, a);
		Deg[a]++, Deg[b]++;
	}
	//DFS(1);
	ll ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * Fac[Deg[i]] % P;
	printf("%lld\n", (ans * n % P + P) % P);
	return 0;
}