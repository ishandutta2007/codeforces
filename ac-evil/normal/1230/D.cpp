#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define ll long long
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

inline ll read() {
	ll w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
	return w * f;
}

const int maxn = 7000 + 5;

int N;
struct Peo {
	ll a, b;
	bool operator < (const Peo &rhs) const {
		return a < rhs.a;
	}
} A[maxn];

ll c[maxn], w[maxn];
int Begin[maxn], n;
int vis[maxn];

int main() {
	N = read();
	rep(i, 1, N) A[i].a = read();
	rep(i, 1, N) A[i].b = read();

	sort(A+1, A+N+1);
	for (register int l = 1, r = 1; l <= N; l = r) {
		while (r <= N && A[r].a == A[l].a) r++;
		n++;
		if (l < r-1) Begin[n] = 1;
		rep(i, l, r-1) c[n] += A[i].b;
		w[n] = A[l].a;
	}

	ll ans = 0;
	memset(vis, 0, sizeof(vis));

	rep(i, 1, n) if (Begin[i])
		rep(j, 1, n) if ((w[i] | w[j]) == w[i]) vis[j] = 1;
	rep(i, 1, n) ans += vis[i] ? c[i] : 0;
	printf("%lld", ans);

	return 0;
}