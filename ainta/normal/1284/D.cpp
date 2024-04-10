#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 524288
using namespace std;
int n;
struct point {
	int b, e, num;
	bool operator <(const point &p)const {
		return e < p.e;
	}
}AA[101000], BB[101000], T[101000];
int X[401000], CX;

struct Tree{
	int S[SZ + SZ], K[SZ+SZ];
	void init() {
		for (int i = 0; i < SZ + SZ; i++)S[i] = K[i] = 0;
	}
	void Add2(int nd, int x) {
		S[nd] |= x;
		K[nd] |= x;
	}
	void Spread(int nd) {
		Add2(nd*2,K[nd]);
		Add2(nd*2+1, K[nd]);
		K[nd] = 0;
	}
	void UDT(int nd) {
		S[nd] = S[nd * 2] | S[nd * 2 + 1];
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
	int Get(int nd, int b, int e, int s, int l) {
		if (s > l)return 0;
		if (s <= b && e <= l)return S[nd];
		Spread(nd);
		int m = (b + e) >> 1, r = 0;
		if (s <= m)r |= Get(nd * 2, b, m, s, l);
		if (l > m)r |= Get(nd * 2 + 1, m + 1, e, s, l);
		return r;
	}
}IT;

bool OK(vector<point>A, vector<point>B, int ck) {
	int i;
	sort(A.begin(), A.end());
	int sz = A.size(), pv = 0;


	for (i = 0; i < sz; i++) {
		T[i] = A[i];
		swap(T[i].b, T[i].e);
	}
	sort(T, T + sz);
	for (i = 0; i < sz; i++) {
		swap(T[i].b, T[i].e);
	}
	IT.init();

	for (i = 0; i < sz;i++) {
		auto t = T[i];
		while (pv < sz && A[pv].e < t.b) {
			int tt = A[pv].num;
			point z;
			if (!ck) z = BB[tt];
			else z = AA[tt];
			IT.Add(1, 1, CX, z.b, z.e, 1);
			pv++;
		}
		int tt = t.num;
		point z;
		if (!ck) z = BB[tt];
		else z = AA[tt];
		if (IT.Get(1, 1, CX, z.b, z.e) != 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int i;
	vector<point>A, B;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int b1, e1, b2, e2;
		scanf("%d%d%d%d", &b1, &e1, &b2, &e2);
		AA[i] = { b1,e1 };
		BB[i] = { b2,e2 };
		X[++CX] = AA[i].b;
		X[++CX] = AA[i].e;
		X[++CX] = BB[i].b;
		X[++CX] = BB[i].e;
	}
	sort(X + 1, X + CX + 1);
	for (i = 0; i < n; i++) {
		int b1, e1, b2, e2;
		b1 = lower_bound(X + 1, X + CX + 1, AA[i].b) - X;
		e1 = lower_bound(X + 1, X + CX + 1, AA[i].e) - X;
		b2 = lower_bound(X + 1, X + CX + 1, BB[i].b) - X;
		e2 = lower_bound(X + 1, X + CX + 1, BB[i].e) - X;
		A.push_back({ b1,e1, i });
		B.push_back({ b2, e2, i })
;
		AA[i] = { b1,e1 };
		BB[i] = { b2,e2 };
	}
	if (OK(A, B, 0) && OK(B, A, 1)) {
		puts("YES");
	}
	else puts("NO");
}