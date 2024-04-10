#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define SZ 131072
using namespace std;
long long Mod = 998244353, TP[2][2];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
int n;
struct point {
	long long d, v;
	int x, c1, c2;
	bool operator <(const point &p)const {
		return d * p.v < p.d*v;
	}
}w[401000];
long long X[101000], V[101000], P[101000], gg;
struct Tree {
	long long R[SZ+SZ][2][2];
	void UDT(int nd) {
		int i, j, k;
		for (i = 0; i < 2; i++)for (j = 0; j < 2; j++)R[nd][i][j] = 0;
		for (i = 0; i < 2; i++)for (k = 0; k < 2; k++)for (j = 0; j < 2; j++)R[nd][i][j] = (R[nd][i][j] + R[nd * 2][i][k] * R[nd * 2 + 1][k][j]) % Mod;
	}
	void init(int nd, int b, int e) {
		if (b == e) {
			R[nd][0][0] = R[nd][1][0] = (Mod + 1 - P[b])%Mod;
			R[nd][0][1] = R[nd][1][1] = P[b];
			if (b == 1)R[nd][1][0] = R[nd][1][1] = 0;
			return;
		}
		int m = (b + e) >> 1;
		init(nd * 2, b, m);
		init(nd * 2 + 1, m + 1, e);
		UDT(nd);
	}
	void Del(int nd, int b, int e, int x, int c1, int c2, int ck) {
		if (b == e) {
			if (ck) {
				for (int i = 0; i < 2; i++){
					for (int j = 0; j < 2; j++) {
						if (i != c1 || j != c2) {
							TP[i][j] = R[nd][i][j];
							R[nd][i][j] = 0;
						}
					}
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if (i != c1 || j != c2) {
							R[nd][i][j] = TP[i][j];
						}
						else R[nd][i][j] = 0;
					}
				}
			}
			return;
		}
		int m = (b + e) >> 1;
		if (x <= m)Del(nd * 2, b, m, x, c1, c2,ck);
		else Del(nd * 2 + 1, m + 1, e, x, c1, c2,ck);
		UDT(nd);
	}
}T;
int main() {
	int i, cnt = 0, j, k;
	scanf("%d", &n);
	long long i100 = Pow(100, Mod - 2);
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &X[i], &V[i], &P[i]);
		P[i] = P[i] * i100%Mod;
	}
	for (i = 1; i < n; i++) {
		w[cnt++] = { X[i + 1] - X[i], V[i] + V[i + 1], i, 1,0 };
		if (V[i] < V[i + 1]) {
			w[cnt++] = { X[i + 1] - X[i], V[i + 1] - V[i], i, 0,0 };
		}
		else {
			w[cnt++] = { X[i + 1] - X[i], V[i] - V[i + 1], i, 1,1 };
		}
	}
	sort(w, w + cnt);
	T.init(1, 1, n);
	long long res = 0;
	for (i = 0; i < cnt; i++) {
		long long l = w[i].d*Pow(w[i].v, Mod - 2) % Mod;
		int x = w[i].x;

		T.Del(1, 1, n, x+1, w[i].c1, w[i].c2, 1);

		res = (res + (T.R[1][0][0] + T.R[1][0][1])*l) % Mod;
		T.Del(1, 1, n, x+1, w[i].c1, w[i].c2, 0);

	
	}
	printf("%lld\n", res);
}