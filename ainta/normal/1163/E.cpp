#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000];
int U[40], cnt, T[40];
void Ins(int a) {
	int i, st = a;
	for (i = 20; i >= 0; i--) {
		if ((a >> i) & 1) {
			a ^= U[i];
		}
		if ((a >> i) & 1) {
			U[i] = a;
			T[i] = st;
			return;
		}
	}
}
int KK;
void Go(int st, int &ed, int pv) {
	if (pv == KK) {
		int s = 0;
		for (int i = 0; i < KK; i++) {
			if ((st >> i) & 1)s ^= T[i];
		}
		printf("%d ", s);
		ed = st;
		return;
	}
	int tp, tp2;
	Go(st, tp, pv + 1);
	Go(tp ^ (1 << pv), tp2, pv + 1);
	ed = tp2;
}
bool Pos(int K) {
	int i;
	KK = K;
	for (i = 0; i <= 20; i++)U[i] = T[i] = 0;
	for (i = 1; i <= n; i++) {
		if (w[i] >= (1 << K))continue;
		Ins(w[i]);
	}
	for (i = 0; i < K; i++) {
		if (!U[i])return false;
	}
	printf("%d\n", K);
	int a = 0;
	Go(0, a, 0);
	puts("");
	return true;
}
int main() {
	int i, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 19; i >= 0; i--) {
		if (Pos(i)) {
			return 0;
		}
	}
}