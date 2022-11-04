#include <bits/stdc++.h>
#define M 1000010
#define PLL pair <ll, ll>
#define x first
#define y second

using namespace std;

typedef long long ll;

int Head[M], Next[M], Go[M], Cnt = 0, n;

ll F[M], Sz[M], ans = 0;

void addedge(int x, int y) {
	Go[++Cnt] = y;
	Next[Cnt] = Head[x];
	Head[x] = Cnt;
}

ll C(ll x) {return x * (x - 1) / 2;}

void DFS(int x, int f) {
	Sz[x] = 1, F[x] = 1e18;
	vector <PLL> V(0);
	for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) DFS(Go[T], x), Sz[x] += Sz[Go[T]], V.push_back(PLL(Sz[Go[T]], 2 * F[Go[T]] + (Sz[Go[T]] - 2 * n + 1) * Sz[Go[T]]));
	if(V.empty()) {F[x] = 0; return;}
	for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) F[x] = min(F[x], C(Sz[x] - Sz[Go[T]]) + F[Go[T]]);
	sort(V.begin(), V.end());
	vector <PLL> O(0);
	for(int i = 0; i < V.size(); i++)
		if(i <= 1 || V[i].x != V[i - 2].x) O.push_back(V[i]);
	for(int i = 0; i < O.size(); i++)
		for(int j = i + 1; j < O.size(); j++)
			ans = max(ans, 1LL * n * (n - 1) - O[i].y - O[j].y - 2LL * O[i].x * O[j].x);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b);
		addedge(b, a);
	}
	DFS(1, 0);
	printf("%lld\n", max(ans / 2, C(n) * 2 - F[1]));
	return 0;
}