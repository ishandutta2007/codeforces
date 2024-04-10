#include<cstdio>
#include<algorithm>
#define N_ 301000
#define SZ 524288
using namespace std;
int n, A, B, C, D, start, len, typ[N_];
struct point {
	int t, ck, num, type;
	bool operator <(const point &p)const {
		return t < p.t;
	}
}w[N_ * 2];
long long L[SZ + SZ], S[SZ + SZ], res = 1e18;
void Put(int a, long long b) {
	a += SZ;
	S[a] = b;
	L[a] = min(0ll, b);
	while (a != 1) {
		a >>= 1;
		S[a] = S[a * 2] + S[a * 2 + 1];
		L[a] = min(L[a * 2], L[a * 2 + 1] + S[a * 2]);
	}
}
void Go(int a) {
	if (w[a].ck == 1) {
		if (w[a].type == 1) {
			Put(w[a].num, C);
		}
		else {
			Put(w[a].num, -D);

		}
	}
	else {
		if (w[a].type == 1) {
			Put(w[a].num, A);
		}
		else {
			Put(w[a].num, -B);
		}
	}
}
int main() {
	int i, t, type, cnt = 0;
	scanf("%d%d%d%d%d%d%d", &n, &A, &B, &C, &D, &start, &len);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &t, &type);
		typ[i] = type;
		w[cnt++] = { max(0, t - len + 1), 1, i, type };
		w[cnt++] = { t + 1, -1, i, type };
	}
	sort(w, w + cnt);
	Put(0, start);
	for (i = 1; i <= n; i++) {
		if (typ[i] == 1)Put(i, A);
		else Put(i, -B);
	}
	if (w[0].t != 0) {
		puts("0");
		return 0;
	}
	int pv = 0;
	for (i = 0; i < cnt; i++) {
		for (int j = i; j < cnt && w[j].t == w[i].t; j++) {
			Go(j);
			if (w[j].ck == 1)pv = max(pv, w[j].num);
			i = j;
		}
		int tmp = S[SZ + pv + 1];
		Put(pv + 1, 1e18);
		if (L[1] >= 0) {
			printf("%d\n", w[i].t);
			return 0;
		}
		Put(pv + 1, tmp);
	}
	puts("-1");
}