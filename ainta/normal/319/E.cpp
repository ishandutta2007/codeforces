#include<cstdio>
#include<algorithm>
#define SZ 262144
using namespace std;
int T[101000], Num[201000];
int n, INF = 1e9;
struct Tree {
	int IT[SZ + SZ];
	void init() {
		for (int i = 0; i < SZ + SZ; i++)IT[i] = -INF;
	}
	void Put(int a, int b) {
		a += SZ;
		IT[a] = b;
		while (a != 1) {
			a >>= 1;
			IT[a] = max(IT[a * 2], IT[a * 2 + 1]);
		}
	}
	int Max(int b, int e) {
		int r = -INF, pv = SZ;
		b += SZ, e += SZ;
		while (b <= e) {
			if (r < IT[b])r = IT[b], pv = b;
			if (r < IT[e])r = IT[e], pv = e;
			b = (b + 1) >> 1, e = (e - 1) >> 1;
		}
		while (pv < SZ) {
			pv *= 2;
			if (IT[pv] != r)pv++;
		}
		return pv - SZ;
	}
}T1,T2;
struct point {
	int ck, b, e;
}w[101000], U[101000];
struct XX {
	int a, b, num;
	bool operator<(const XX &p)const {
		if (a != p.a)return a < p.a;
		if ((a > b) != (p.a > p.b))return a > b;
		return b > p.b;
	}
}X[201000];
int CX, UF[201000];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Merge(int a, int b) {
	a = Find(a), b = Find(b);
	UF[a] = b;
}

void Del(int a) {
	T1.Put(w[a].b, -INF);
	T2.Put(w[a].e, -INF);
}

void Ins(int b, int e, int num) {
	int i, bb = b, ee = e;
	while (1) {
		int pv = T1.Max(1, e - 1);
		if (T1.IT[SZ + pv] <= e) break;
		ee = max(ee, T1.IT[SZ + pv]);
		Merge(num, Num[pv]);
		Del(Num[pv]);
	}

	while (1) {
		int pv = T2.Max(b + 1, CX);
		if (T2.IT[SZ + pv] <= -b) break;
		bb = min(bb, -T2.IT[SZ + pv]);
		Merge(num, Num[pv]);
		Del(Num[pv]);
	}
	T1.Put(bb, ee);
	T2.Put(ee, -bb);
	U[Find(num)].b = bb, U[Find(num)].e = ee;
}
int main() {
	int i, c = 0, a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		UF[i] = i;
		scanf("%d%d%d", &w[i].ck, &w[i].b, &w[i].e);
		U[i] = w[i];
		if (w[i].ck == 1) {
			X[++CX] = { w[i].b,w[i].e,i * 2 };
			X[++CX] = { w[i].e,w[i].b,i * 2 + 1 };
		}
	}
	sort(X + 1, X + CX + 1);
	for (i = 1; i <= CX; i++) {
		if (X[i].num & 1)w[X[i].num / 2].e = i;
		else w[X[i].num / 2].b = i;
	}
	for (i = 1; i <= n; i++) {
		if (w[i].ck == 1) {
			Num[w[i].b] = Num[w[i].e] = i;
		}
	}
	T1.init();
	T2.init();
	for (i = 1; i <= n; i++) {
		if (w[i].ck == 1) {
			T[++c] = i;
			Ins(w[i].b, w[i].e, i);
		}
		else {
			a = Find(T[w[i].b]), b = Find(T[w[i].e]);
			if (U[a].b >= U[b].b && U[a].e <= U[b].e) {
				puts("YES");
			}
			else {
				puts("NO");
			}
		}
	}
}