#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int D[3010][3010], Mod = 1000000007, n, K;
vector<int>E[3010];
void DFS(int a) {
	int i, j;
	if (E[a].empty()) {
		for (i = 1; i <= n; i++)D[a][i] = i;
		return;
	}
	for (auto &t : E[a]) {
		DFS(t);
	}
	int s = 0;
	for (i = 1; i <= n; i++) {
		int r = 1;
		for (auto &t : E[a]) {
			r = (long long)r*D[t][i] % Mod;
		}
		s = (s + r) % Mod;
		D[a][i] = s;
	}
}
int TA[3010], TB[3010];
struct poly {
	int w[3010];
	poly() {
		for (int i = 0; i < 3010; i++)w[i] = 0;
	}
	void Mul(int a) {
		int i;
		for (i = 0; i <= n + 1; i++)w[i] = 1ll * w[i] * a%Mod;
	}
	void MulP(int b) {
		int i;
		for (i = 0; i <= n + 1; i++) TA[i] = TB[i] = 0;
		for (i = 0; i <= n; i++) {
			TA[i + 1] = w[i];
			TB[i] = 1ll * w[i] * (Mod - b) % Mod;
		}
		for (i = 0; i <= n + 1; i++)w[i] = (TA[i] + TB[i]) % Mod;
	}
};
poly Add(poly &a, poly &b) {
	poly c;
	for (int i = 0; i <= n + 1; i++)c.w[i] = (a.w[i] + b.w[i]) % Mod;
	return c;
}
poly Div(poly &a, int k) {
	int i, up = 0;
	poly r;
	for (i = n + 1; i >= 1; i--) {
		r.w[i - 1] = (a.w[i] + up) % Mod;
		up = 1ll * r.w[i - 1] * k%Mod;
	}
	return r;
}
int III[6010];
int Pow(int a, int b) {
	if (a < 0)a += Mod;
	int r = 1;
	while (b) {
		if(b&1)r = 1ll * r*a%Mod;
		a = 1ll * a*a%Mod; b >>= 1;
	}
	return r;
}
int Inv(int a) {
	return III[n + a];
}
int main() {
	int i, j, a;
	scanf("%d%d", &n,&K);
	for (i = -n; i <= n; i++) {
		if (i != 0) {
			III[n + i] = Pow(i, Mod - 2);
		}
	}
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		//a = rand() % (i - 1) + 1;
		E[a].push_back(i);
	}
	DFS(1);
	poly res;
	poly tp, ttt;
	tp.w[0] = 1;
	for (i = 0; i <= n; i++) {
		tp.MulP(i);
	}
	for (i = 0; i <= n; i++) {
		ttt = Div(tp, i);
		int c = 1;
		for (j = 0; j <= n; j++) {
			if (i != j) {
				c = 1ll * c*Inv(i - j) % Mod;
			}
		}
		ttt.Mul(D[1][i]);
		ttt.Mul(c);
		res = Add(res, ttt);
	}
	long long rr = 0, tt = 1;
	for (i = 0; i <= n; i++) {
		rr = (rr + tt*res.w[i]) % Mod;
		tt = tt*K%Mod;
	}
	printf("%lld\n", rr);
}