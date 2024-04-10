#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 601000
#define SZ 1048576
using namespace std;
int w[N_], oto[N_], par[N_][20];
char p[N_];
int n, st[N_][2];
long long ans;

struct Tree {
	long long S[SZ + SZ];
	int C[SZ + SZ], K[SZ + SZ];

	void init() {
		for (int i = 0; i < SZ + SZ; i++)K[i] = -1;
	}

	void UDT(int nd) {
		S[nd] = S[nd * 2] + S[nd * 2 + 1];
		C[nd] = C[nd * 2] + C[nd * 2 + 1];
	}
	void Put2(int nd, int x) {
		K[nd] = x;
		S[nd] = (long long)C[nd] * x;
	}
	void Spread(int nd) {
		if (K[nd] != -1) {
			Put2(nd * 2, K[nd]);
			Put2(nd * 2 + 1, K[nd]);
		}
		K[nd] = -1;
	}

	void Off(int nd, int b, int e, int x) {
		if (b == e) {
			C[nd] = 0;
			S[nd] = 0;
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if(x<=m)Off(nd * 2, b, m, x);
		else Off(nd * 2 + 1, m + 1, e, x);
		UDT(nd);
	}
	void On(int nd, int b, int e, int x) {
		if (b == e) {
			C[nd] = 1;
			S[nd] = 0;
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (x <= m)On(nd * 2, b, m, x);
		else On(nd * 2 + 1, m + 1, e, x);
		UDT(nd);
	}
	void Put(int nd, int b, int e, int s, int l, int x) {
		if (s > l)return;
		if (s <= b && e <= l) {
			Put2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Put(nd * 2, b, m, s, l, x);
		if (l > m)Put(nd * 2 + 1, m + 1, e, s, l, x);
		UDT(nd);
	}

}T;





void Go(int a, int b, int len) {
	int i;
	for (i = 19; i >= 0; i--) if (par[a][i] > par[b][i])a = par[a][i], b = par[b][i];
	if (par[b][0] == 0) {
		return;
	}
	a = par[a][0], b = par[b][0];
	while (b >= a && b) {
		T.Off(1, 1, n, len - b);
		b = par[b][0];
	}
	if (a&&b) {
		Go(a, b, len);
	}

}

int main() {
	char pp[3];
	int i, j, top = 0;
	scanf("%d", &n);
	oto[0] = -1;
	T.init();
	long long mask = (1 << 30) - 1;
	for (i = 1; i <= n; i++) {
		scanf("%s", pp);
		long long a;
		scanf("%lld", &a);
		pp[0] = (pp[0] - 'a' + ans) % 26 + 'a';
		a = (ans&mask) ^ a;
		w[i] = a;
		p[i - 1] = pp[0];
		int t = oto[i - 1];
		while (t != -1 && p[i - 1] != p[t]) t = oto[t];
		oto[i] = t + 1;

		while (top && st[top][0] >= w[i]) top--;
		top++;
		st[top][0] = w[i];
		st[top][1] = i;
		if (p[0] == p[i - 1]) {
			T.On(1, 1, n, i);
		}
		T.Put(1, 1, n, st[top - 1][1] + 1, i, w[i]);

		par[i][0] = oto[i];
		for (j = 0; j < 19; j++)par[i][j + 1] = par[par[i][j]][j];
		Go(i, i - 1, i);

		ans += T.S[1];

		printf("%lld\n", ans);
	}
}