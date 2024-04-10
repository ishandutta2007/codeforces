#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n;
long long C, w[N], Min[N], Dif[N];
bool All[N];
struct Interval {
	long long l, r;
	Interval() {}
	Interval(long long _l, long long _r): l(_l), r(_r) {}
	bool Contain(long long x) { return l <= x && x <= r; }
} que[N * 2];
int ql, qr;
long long sgn, dlt;
inline long long dec(long long x) {
	return x * sgn + dlt;
}
inline long long enc(long long x) {
	return (x - dlt) * sgn;
}
int main() {
	scanf("%d%lld", &n, &C);
	sgn = 1, dlt = 0;
	ql = N, qr = N - 1;
	que[++qr] = Interval(0, C);
	for (int i = 1; i <= n - 2; i++) {
		scanf("%lld", &w[i]);
#define maxR (sgn > 0 ? que[qr].r : que[ql].l)
#define maxL (sgn > 0 ? que[qr].l : que[ql].r)
		while (ql <= qr && dec(maxR) > w[i]) {
			if (dec(maxL) <= w[i]) {
				maxR = enc(w[i]);
				break;
			} else {
				sgn > 0 ? qr-- : ql++;
			}
		}
		if (ql <= qr && (sgn > 0 ? que[qr].Contain(enc(w[i])) : que[ql].Contain(enc(w[i])))) {
			sgn = 1, dlt = 0;
			ql = N, qr = N - 1;
			que[++qr] = Interval(0, w[i]);
			All[i] = 1;
			continue;
		}
		sgn = -sgn, dlt = w[i] - dlt;
		if (ql <= qr && dec(maxR) != w[i]) {
			(sgn > 0 ? que[++qr] : que[--ql]) = Interval(enc(w[i]), enc(w[i]));
		}
		if (ql > qr) {
			puts("NO");
			return 0;
		}
		Min[i] = dec(sgn > 0 ? que[ql].l : que[qr].r);
	}
	puts("YES");
	long long cur = dec(sgn > 0 ? que[ql].l : que[qr].r);
	sgn = 1;
	for (int i = n - 2; i >= 1; i--) {
		Dif[i] = cur * sgn;
		if (All[i]) cur = w[i], sgn = -sgn;
		else if (cur == w[i]) cur = Min[i - 1], sgn = -sgn;
		else cur = w[i] - cur;
	}
	Dif[0] = cur * sgn;
	long long t = cur = 0;
	for (int i = 0; i <= n - 2; i++) {
		cur += Dif[i];
		t = min(t, cur);
	}
	cur = -t;
	printf("%lld", cur);
	for (int i = 0; i <= n - 2; i++) {
		cur += Dif[i];
		printf(" %lld", cur);
	}
	printf("\n");
	return 0;
}