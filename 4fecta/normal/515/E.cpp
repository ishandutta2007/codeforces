#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int N, days, n;
ll D[200200], h[200200], cd[200200];

ll mn[400400], mx[400400];

ll qmin (int l, int r) {
	ll res = 1e18;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l&1) res = min(res, mn[l++]);
		if (r&1) res = min(res, mn[--r]);
	}
	return res;
}

ll qmax (int l, int r) {
	ll res = 0;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l&1) res = max(res, mx[l++]);
		if (r&1) res = max(res, mx[--r]);
	}
	return res;
}

struct range {
	int rs, re;
	ll best;
} r[800800];

void init (int i, int L, int R) {
	r[i] = {L, R, 0};
	if(L != R-1) {
		int M = (L+R)/2;
		init(i*2 + 1, L, M);
		init(i*2 + 2, M, R);
		r[i].best = max(r[i*2+1].best, r[i*2+2].best);
		r[i].best = max(r[i].best, qmax(M, R) - qmin(L, M));
	}
}

ll query (int i, int qs, int qe) {
	if(qs == r[i].rs && qe == r[i].re) {
		return r[i].best;
	}
	ll b = 0;
	int M = (r[i].rs + r[i].re) / 2;
	if(qs < M) {
		b = max(b, query(i*2 + 1, qs, min(qe, M)));
	}
	if(qe > M) {
		b = max(b, query(i*2 + 2, max(qs, M), qe));
	}
	if (qs < M && qe > M) {
		b = max(b, qmax(max(qs, M), qe) - qmin(qs, min(qe, M)));
	}
	return b;
}

int main () {
	scanf("%d %d", &N, &days);
	fo(i, N) scanf("%lld", &D[i]), D[i+N] = D[i];
	fo(i, N) scanf("%lld", &h[i]), h[i+N] = h[i];
	n = N*2;
	for(int i = 1; i < n; i++)
		cd[i] = cd[i-1] + D[i-1];

	fo(i, n) {
		mn[i + n] = -h[i]*2 + cd[i];
		mx[i + n] = h[i]*2 + cd[i];
	}
	for(int i = n-1; i > 0; i--) {
		mn[i] = min(mn[i*2], mn[i*2+1]);
		mx[i] = max(mx[i*2], mx[i*2+1]);
	}

	init(0, 0, n);

	fo(i, days) {
		int a, b;
		scanf("%d %d\n", &a, &b);
		a--, b--;
		if(a <= b) {
			printf("%lld\n", query(0, b + 1, a + N));
		} else {
			printf("%lld\n", query(0, b + 1, a));
		}
	}
	return 0;
}