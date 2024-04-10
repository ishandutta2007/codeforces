#include<cstdio>
#include<algorithm>
using namespace std;
#define SZ 1048576
char p[101000], q[1010000], U[1010000], V[1010000];
int CC[2], n, m, res;

int Rank[1010000], SA[1010000], ord[1010000], C[1010000], ord1[1010000], ord2[1010000], IT[SZ+SZ];
struct AA {
	int a, b;
}w[1010000];
void Put(int a, int b) {
	a += SZ;
	IT[a] = b;
	while (a != 1) {
		a >>= 1;
		IT[a] = min(IT[a * 2], IT[a * 2 + 1]);
	}
}
int Get(int a, int b) {
	a = Rank[a], b = Rank[b];
	if (a > b)swap(a, b);
	b--;
	a += SZ, b += SZ;
	int r = 1e9;
	while (a <= b) {
		r = min(r, min(IT[a], IT[b]));
		a = (a + 1) >> 1, b = (b - 1) >> 1;
	}
	return r;
}
void Suffix_Array(int n) {
	int i, L = 1;
	for (i = 0; i < n; i++) {
		w[i].a = q[i];
		w[i].b = q[i + 1];
	}
	int M = max(n, 200);
	while (1) {
		for (i = 0; i <= M; i++) C[i] = 0;
		for (i = 0; i < n; i++)C[w[i].b]++;
		for (i = 1; i <= M; i++)C[i] += C[i - 1];
		for (i = 0; i < n; i++)ord1[--C[w[i].b]] = i;
		for (i = 0; i <= M; i++) C[i] = 0;
		for (i = 0; i < n; i++)C[w[i].a]++;
		for (i = 1; i <= M; i++)C[i] += C[i - 1];
		for (i = n - 1; i >= 0; i--)ord2[--C[w[ord1[i]].a]] = ord1[i];
		int cnt = 0;
		for (i = 0; i < n; i++) {
			if (i == 0 || w[ord2[i]].a != w[ord2[i - 1]].a || w[ord2[i]].b != w[ord2[i - 1]].b) {
				cnt++;
			}
			Rank[ord2[i]] = cnt;
		}
		if (cnt == n)break;
		L <<= 1;
		for (i = 0; i < n; i++) {
			w[i].a = Rank[i];
			if (i + L >= n)w[i].b = 0;
			else w[i].b = Rank[i + L];
		}
	}
	for (i = 0; i < n; i++) {
		SA[Rank[i]] = i;
	}
	int t = 0;
	for (i = 0; i < n; i++) {
		int x = Rank[i];
		if (t)t--;
		if (x == n)continue;
		int y = SA[x + 1];
		while (q[i + t] == q[y + t])t++;
		Put(x, t);
	}
}

bool Pos(int L1, int L2) {
	int i, j, CK[2] = { -1, -1};
	int pv = 0;
	for (i = 0; i < n; i++) {
		if (p[i] == '0') {
			if (CK[0] == -1)CK[0] = pv;
			else {
				if (Get(CK[0], pv) < L1)return false;
			}
			pv += L1;
		}
		else {
			if (CK[1] == -1)CK[1] = pv;
			else {
				if (Get(CK[1], pv) < L2)return false;
			}
			pv += L2;
		}
	}
	if (L1 == L2) {
		if (Get(CK[0], CK[1]) >= L1)return false;
	}
	return true;
}
int main() {
	int i;
	scanf("%s", p);
	scanf("%s", q);
	for (i = 0; p[i]; i++) {
		CC[p[i] - '0']++;
	}
	n = i;
	for (i = 0; q[i]; i++);
	m = i;
	Suffix_Array(m);
	for (i = 1; i <= m; i++) {
		long long t = m - 1ll * i * CC[0];
		if (t <= 0 || t % CC[1] != 0) continue;
		if (Pos(i, t / CC[1])) {
			res++;
		}
	}
	printf("%d\n", res);
}