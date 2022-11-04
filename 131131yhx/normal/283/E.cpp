#include <bits/stdc++.h>
#define M 800010
#define lb lower_bound
#define ub upper_bound
#define goleft x + x, L, (L + R) / 2, l, min(r, (L + R) / 2)
#define goright x + x + 1, (L + R) / 2 + 1, R, max(l, (L + R) / 2 + 1), r
#define pd(x, l, r, md) if(Tg[x]) Tg[x + x] ^= 1, Tg[x + x + 1] ^= 1, Sm[x + x] = md - l + 1 - Sm[x + x], Sm[x + x + 1] = r - md - Sm[x + x + 1], Tg[x] = 0;

using namespace std;

typedef long long ll;

int X[M], L[M], R[M], Head[M], Next[M], Go[M], Cnt = 0, n, m, Tg[M], Sm[M];

ll ans = 0;

inline void addedge(int x, int y) {Go[++Cnt] = y, Next[Cnt] = Head[x], Head[x] = Cnt;}

void Rev(int x, int L, int R, int l, int r)
{
	if(L == l && R == r) Tg[x] ^= 1, Sm[x] = (R - L + 1) - Sm[x]; else {
		pd(x, L, R, (L + R) / 2);
		if(l <= (L + R) / 2) Rev(goleft); if(r > (L + R) / 2) Rev(goright);
		Sm[x] = Sm[x + x] + Sm[x + x + 1];
	}
}

int Ask(int x, int L, int R, int l, int r, int ans = 0)
{
	if(L == l && R == r) return Sm[x];
	pd(x, L, R, (L + R) / 2);
	if(l <= (L + R) / 2) ans = Ask(goleft); if(r > (L + R) / 2) ans += Ask(goright);
	return ans;
}
	
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
	for(int i = 1; i <= m; i++) scanf("%d%d", &L[i], &R[i]);
	sort(X + 1, X + n + 1);
	for(int i = 1; i <= m; i++) L[i] = lb(X + 1, X + n + 1, L[i]) - X, addedge(L[i], i);
	for(int i = 1; i <= m; i++) R[i] = ub(X + 1, X + n + 1, R[i]) - X - 1, addedge(R[i] + 1, i);
	for(int i = 1; i <= n; i++) {
		for(int T = Head[i]; T; T = Next[T]) if(L[Go[T]] <= R[Go[T]]) Rev(1, 1, n, L[Go[T]], R[Go[T]]);
		ll a1 = i == 1 ? 0 : Ask(1, 1, n, 1, i - 1), a2 = i == n ? 0 : Ask(1, 1, n, i + 1, n);
		ans = ans + (a1 + n - i - a2) * (a2 + i - 1 - a1);
	}
	return printf("%lld\n", (ans - (ll) n * (n - 1) * (n - 2) / 6) / 2), 0;
}