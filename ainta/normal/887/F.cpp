#include<cstdio>
#include<algorithm>
#define SZ 524288
#define N_ 501000
using namespace std;
int n, K, w[N_], IT[SZ+SZ], X[SZ], chk[SZ], S[SZ], sum;
void Put(int a, int b) {
	a += SZ;
	IT[a] = b;
	while (a != 1) {
		a >>= 1;
		IT[a] = min(IT[a*2], IT[a*2+1]);
	}
}
int Min(int b, int e) {
	int r = 1e9;
	b += SZ, e += SZ;
	while (b <= e) {
		r = min(r, IT[b]);
		r = min(r, IT[e]);
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
struct Tree {
	int Mn, x;
}T[SZ+SZ];
void Ins(int a, int b) {
	a += SZ;
	while (a) {
		T[a].Mn = min(T[a].Mn, b);
		a >>= 1;
	}
}
int Get(int b, int e) {
	b += SZ, e += SZ;
	int r = 1e9;
	while (b <= e) {
		r = min(r, min(T[b].Mn, T[e].Mn));
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
int main() {
	int i, Mx;
	for (i = 1; i < SZ + SZ; i++)T[i].Mn = 1e9;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		X[i] = w[i];
	}
	sort(X + 1, X + n + 1);
	for (i = 1; i <= n; i++) {
		w[i] = lower_bound(X + 1, X + n + 1, w[i]) - X;
		Put(i, w[i]);
	}
	for (i = 1; i <= n - K; i++) {
		if (Min(i, i + K) == w[i]) {
			chk[i] = 1;
			Mx = i;
			sum++;
		}
		S[i] = S[i - 1] + chk[i];
	}
	if (!sum) {
		puts("YES");
		return 0;
	}
	for (i = n; i >= 1; i--) {
		if (!chk[i]) {
			int t = S[i - 1] - S[max(i - K - 1, 0)];
			int b, e;
			if (t) e = Min(max(i - K, 1), i) - 1;
			else e = w[i] - 1;

			b = Min(i + 1, min(i + K, n + 1)) + 1;
			if (b <= e) {
				if (t == sum - 1 && i < Mx && b <= w[Mx] && w[Mx] <= e) {
					if (Min(Mx + 1, min(Mx + K, n + 1)) < w[i]) {
						puts("YES");
						return 0;
					}
				}
				if (t == sum) {
					if (Get(b, e) < w[i]) {
						puts("YES");
						return 0;
					}
				}
			}
		}
		Ins(w[i], Min(i + 1, min(i + K, n + 1)));
	}
	puts("NO");
}