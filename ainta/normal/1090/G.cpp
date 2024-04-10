#include<cstdio>
#include<algorithm>
#define N_ 501000
#define SZ 1048576
const int BS = 524288;
using namespace std;
int A[N_], n, B[N_], cnt, Fin[N_];
long long MM = 1048576;
struct Node {
	int l, r, dep, xx;
	long long QQ, RR;
}T[N_*22];
int Q, Root[N_];
long long po[SZ+1], INF = 1e9;
bool NegOrZero(Node A, int b, int e) {
	if (A.QQ == 0) return A.RR <= 0;
	return A.QQ < 0;
}
void UDT(int nd, int b, int e, int m) {
	int c2 = T[nd].r, c1 = T[nd].l;

	if (e - b + 1 <= 16) {
		T[nd].RR = T[c2].RR*po[m - b + 1] + T[c1].RR;
		return;
	}
	if (e - b + 1 == 32) {
		long long t = T[c2].RR*po[m - b + 1] + T[c1].RR;
		long long u = t / MM;
		T[nd].QQ = u;
		T[nd].RR = t - u * MM;
		while (abs(T[nd].RR - MM) < abs(T[nd].RR))T[nd].RR -= MM, T[nd].QQ++;
		while (abs(T[nd].RR + MM) < abs(T[nd].RR))T[nd].RR += MM, T[nd].QQ--;
		return;
	}

	if (e - b + 1 == 64) {
		long long AA = T[c2].QQ;
		long long BB = T[c1].QQ + T[c2].RR * (1<<12);
		long long CC = T[c1].RR;
		CC += BB * MM;
		long long z = CC / (1ll << 44);
		CC -= (z << 44);
		AA <<= 8;
		AA += z;
		long long MM2 = (1ll << 44);
		while (abs(CC + MM2) < abs(CC)) {
			CC += MM2;
			AA--;
		}
		while (abs(CC - MM2) < abs(CC)) {
			CC -= MM2;
			AA++;
		}
		T[nd].QQ = AA;
		if (CC > INF)CC = INF;
		if (CC < -INF)CC = -INF;
		T[nd].RR = CC;
		return;
	}

	long long AA = T[c2].QQ;
	long long BB = T[c1].QQ + (T[c2].RR << 20);
	long long CC = T[c1].RR;
	if (BB) {
		if (BB > 0) CC = INF;
		if (BB < 0)CC = -INF;
	}
	T[nd].QQ = AA;
	T[nd].RR = CC;

}
void Add(int nd, int pp, int b, int e, int x, int y) {
	T[nd] = T[pp];
	if (b == e) {
		T[nd].xx = b;
		T[nd].RR += y;
		return;
	}
	int m = (b + e) >> 1;
	if (x <= m) {
		T[nd].l = ++cnt;
		Add(T[nd].l, T[pp].l, b, m, x, y);
	}
	else {
		T[nd].r = ++cnt;
		Add(T[nd].r, T[pp].r, m + 1, e, x, y);
	}
	UDT(nd, b, e, m);
}
int main() {
	int i, ck, a, b;
	scanf("%d", &Q);
	po[0] = 1;
	for (i = 1; i < 60; i++)po[i] = po[i - 1] * 2;
	for (i = 60; i <= SZ; i++)po[i] = 1e18;
	for (int TT = 1; TT <= Q; TT++) {
		scanf("%d", &ck);
		if (ck == 1) {
			n++;
			Root[n] = ++cnt;
			Add(Root[n], Root[0], 0, SZ-1, BS, 1);
			continue;
		}
		if (ck == 2) {
			scanf("%d", &a);
			if (Fin[a])continue;
			A[a]++;
			continue;
		}
		if (ck == 3) {
			scanf("%d", &a);
			if (Fin[a])continue;
			B[a]++;
			continue;
		}
		if (ck == 4) {
			scanf("%d", &a);
			n++;
			A[n] = A[a];
			B[n] = B[a];
			Root[n] = ++cnt;
			T[Root[n]] = T[Root[a]];
			if (Fin[a]) {
				Fin[n] = TT;
				continue;
			}
		}
		if (ck == 5) {
			scanf("%d%d", &a, &b);
			if (Fin[a] || Fin[b])continue;
			int ra = Root[a];
			int rb = Root[b];
			Root[a] = ++cnt;
			Add(Root[a], ra, 0, SZ - 1, A[b] - B[a] + BS, -1);
			Root[b] = ++cnt;
			Add(Root[b], rb, 0, SZ - 1, A[a] - B[b] + BS, -1);
			if (NegOrZero(T[Root[a]], 0, SZ-1)) {
				Fin[a] = TT;
			}
			if (NegOrZero(T[Root[b]], 0, SZ-1)) {
				Fin[b] = TT;
			}
		}
	}
	printf("%d\n", n);
	for (i = 1; i <= n; i++) {
		if (!Fin[i])Fin[i] = -1;
		printf("%d ", Fin[i]);
	}
}