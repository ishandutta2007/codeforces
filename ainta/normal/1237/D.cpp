#include<cstdio>
#include<algorithm>
#define SZ 524288
using namespace std;
int n;
int w[301000], INF = 1e9;
struct Tree {
	int Mn, Mx, M;
}IT[SZ+SZ];
Tree Merge(Tree a, Tree b) {
	Tree r;
	r.Mx = max(a.Mx, b.Mx);
	r.Mn = min(a.Mn, b.Mn);
	r.M = max(max(a.M, b.M), a.Mx > b.Mn*2 ? 1:0);
	return r;
}
void Put(int a, int b) {
	a += SZ;
	IT[a].Mx = b;
	IT[a].Mn = b;
	IT[a].M = 0;
	while (a != 1) {
		a >>= 1;
		IT[a] = Merge(IT[a * 2], IT[a * 2 + 1]);
	}
}
int TP[30];
Tree Get(int b, int e) {
	Tree t = { INF,-INF,0 };
	int c = 0;
	b += SZ, e += SZ;
	while (b <= e) {
		if (b & 1) {
			t = Merge(t, IT[b]);
		}
		if (!(e & 1))TP[c++] = e;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	for (int i = c - 1; i >= 0; i--)t = Merge(t, IT[TP[i]]);
	return t;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		w[i + n] = w[i];
		w[i + n + n] = w[i];
	}
	for (i = 1; i <= n + n + n; i++) {
		Put(i, w[i]);
	}
	for (i = 1; i <= n; i++) {
		int b = i+1, e = i + n+n, r = -1, mid;
		while (b <= e) {
			mid = (b + e) >> 1;
			if (Get(i, mid).M == 1) {
				r = mid;
				e = mid - 1;
			}
			else b = mid + 1;
		}
		if (r != -1)r -= i;
		printf("%d ", r);
	}
}