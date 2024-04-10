#include<cstdio>
#include<algorithm>
#include<random>
#define SZ 262144
using namespace std;
int S[201000][2];
int SS[201000];
char p[201000];
int n;

struct AA {
	int a, b;
}w[201000];
int Rank[201000], SA[201000], ord[201000], C[201000], ord1[201000], ord2[201000], po[201000];

int V[10100];
long long Mod;
struct Tree {
	int L, c;
	long long g;
}IT[SZ+SZ];
Tree Merge(Tree a, Tree b) {
	int l = a.L + b.L;
	int c = a.c + b.c;
	long long g = a.g * po[b.c] % Mod;
	if (b.c) {
		if (!(a.L & 1)) g = (g + b.g) % Mod;
		else g = (g + po[b.c] - b.g - 1 + Mod + Mod) % Mod;
	}
	return { l,c,g };
}
void UDT(int nd) {
	IT[nd] = Merge(IT[nd * 2], IT[nd * 2 + 1]);
}
void Build(int nd, int b, int e) {
	if (b == e) {
		if (p[b] == '0') {
			IT[nd] = { 1,1,1 };
		}
		else {
			IT[nd] = { 1,0,0 };
		}
		return;
	}
	int m = (b + e) >> 1;
	Build(nd * 2, b, m);
	Build(nd * 2 + 1, m + 1, e);
	UDT(nd);
}

Tree Get(int nd, int b, int e, int s, int l) {
	if (s <= b && e <= l)return IT[nd];
	int m = (b + e) >> 1;
	Tree r1 = { 0,0,0 }, r2 = { 0,0,0 };
	if (s <= m)r1 = Get(nd * 2, b, m, s, l);
	if (l > m)r2 = Get(nd * 2 + 1, m + 1, e, s, l);
	return Merge(r1, r2);
}

int main() {
	int i;
	for (i = 0; i < 10000; i++)V[i] = 1e9 + i * 2 + 1;
	random_device rd;
	mt19937 mt(rd());
	shuffle(V, V + 10000, mt);
	for (i = 0;; i++) {
		int j;
		for (j = 2; j*j <= i; j++) {
			if (i%j == 0)break;
		}
		if (j*j > i) {
			Mod = V[i];
			break;
		}
	}
	scanf("%d", &n);
	scanf("%s", p + 1);
	po[0] = 1;
	for (i = 1; i <= n; i++) {
		po[i] = po[i - 1] * 2 % Mod;
	}
	Build(1, 1, n);
	int Q, b1, b2, L;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d%d", &b1, &b2, &L);
		Tree t1 = Get(1, 1, n, b1, b1 + L - 1);
		Tree t2 = Get(1, 1, n, b2, b2 + L - 1);
		if (t1.L == t2.L && t1.g == t2.g && t1.c == t2.c) {
			puts("Yes");
		}
		else puts("No");
	}
}