#include<cstdio>
#include<algorithm>
using namespace std;
#define SZ 131072
int n, pv[2];
long long w[101000];
char p[101000];
struct Tree {
	long long Mn[SZ + SZ], K[SZ + SZ];
	void Add2(int nd, long long x) {
		Mn[nd] += x;
		K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void UDT(int nd) {
		Mn[nd] = min(Mn[nd * 2], Mn[nd * 2 + 1]);
	}
	void Add(int nd, int b, int e, int s, int l, long long x) {
		if (b == s&&e == l) {
			Add2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Add(nd * 2, b, m, s, min(m, l), x);
		if (l>m)Add(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x);
		UDT(nd);
	}
	long long Min(int nd, int b, int e, int s, int l) {
		if (b == s&&e == l)return Mn[nd];
		Spread(nd);
		int m = (b + e) >> 1;
		long long r = 5e18;
		if (s <= m)r = min(r, Min(nd * 2, b, m, s, min(m, l)));
		if (l > m)r = min(r, Min(nd * 2 + 1, m + 1, e, max(m + 1, s), l));
		UDT(nd);
		return r;
	}
	bool OK() {
		return Mn[1] >= 0;
	}
}T;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		w[i] *= 2;
	}
	scanf("%s", p + 1);
	long long s = 0;
	for (i = 1; i <= n; i++) {
		if (p[i] == 'W') {
			if (!pv[0])pv[0] = i;
			s += w[i];
		}
		if (p[i] == 'G') {
			if (!pv[1])pv[1] = i;
			s += w[i];
		}
		if (p[i] == 'L') {
			s -= w[i];
			if (s < 0) {
				long long t = (-s + 1) / 2 * 2;
				if (pv[0]) {
					w[pv[0]] += t;
					s += t;
				}
				else {
					w[pv[1]] += t;
					s += t;
				}
			}
		}
	}
	long long res = 0;
	for (i = 1; i <= n; i++) {
		if (p[i] == 'L') {
			T.Add(1, 1, n, i, n, -w[i]), res += w[i];
		}
		else {
			T.Add(1, 1, n, i, n, w[i]);
			if (p[i] == 'G')res += 5 * w[i];
			else res += 3 * w[i];
		}
	}
	for (i = n; i >= 1; i--) {
		if (p[i] == 'G') {
			long long t = T.Min(1, 1, n, i, n);
			long long g = min(t / 2, w[i]);
			T.Add(1, 1, n, i, n, -g * 2);
			res -= 4 * g;
		}
	}
	for (i = n; i >= 1; i--) {
		if (p[i] == 'W') {
			long long t = T.Min(1, 1, n, i, n);
			long long g = min(t / 2, w[i]);
			T.Add(1, 1, n, i, n, -g * 2);
			res -= 2 * g;
		}
	}
	printf("%lld\n", res/2);
}