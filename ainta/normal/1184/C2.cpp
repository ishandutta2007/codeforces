#include<cstdio>
#include<algorithm>
#define SZ (1<<23)
using namespace std;
int n, R;
struct Seg {
	int x, by, ey, ck;
	bool operator < (const Seg &p)const {
		return x < p.x;
	}
}w[601000];
int cnt = 0;
struct Tree {
	int Mx[SZ + SZ], K[SZ + SZ];
	void Add2(int nd, int x) {
		Mx[nd] += x;
		K[nd] += x;
	}
	void UDT(int nd) {
		Mx[nd] = max(Mx[nd * 2], Mx[nd * 2 + 1]);
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void Add(int nd, int b, int e, int s, int l, int x) {
		if (s > l)return;
		if (s <= b && e <= l) {
			Add2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Add(nd * 2, b, m, s, l, x);
		if (l > m)Add(nd * 2 + 1, m + 1, e, s, l, x);
		UDT(nd);
	}
}T;
int main() {
	int i, x, y;
	scanf("%d%d", &n, &R);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		int tx = x - y, ty = x + y;
		w[cnt++] = { tx - R,ty - R,ty + R , 1};
		w[cnt++] = { tx + R + 1,ty - R,ty + R, -1 };
	}
	sort(w, w + cnt);
	int BS = (1 << 22);
	int res = 0;
	for (i = 0; i < cnt; i++) {
		T.Add(1, 0, SZ - 1, w[i].by + BS, w[i].ey + BS, w[i].ck);
		if (i == cnt - 1 || w[i].x != w[i + 1].x) {
			res = max(res, T.Mx[1]);
		}
	}
	printf("%d\n", res);
}