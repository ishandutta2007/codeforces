#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 1048576
using namespace std;
int n, m, cnt;
int w[1000010], Mod = 998244353;
long long D[1010][1010], DD[1010][1010];
int L[1010], R[1100], IT[SZ+SZ];
int LL[1100], RR[1100];
void Put(int a, int b) {
	a += SZ;
	IT[a] = b;
	while (a != 1) {
		a >>= 1;
		IT[a] = min(IT[a * 2], IT[a * 2 + 1]);
	}
}
int Min(int b, int e) {
	b += SZ, e += SZ;
	int r = 1e9;
	while (b <= e) {
		r = min(r, min(IT[b], IT[e]));
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
struct AA {
	int a, c;
}P[1010];
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
		if(!L[w[i]])L[w[i]] = i;
		R[w[i]] = i;
		Put(i, w[i]);
	}
	for (i = 1; i <= n; i++) {
		if (Min(L[i], R[i]) < i) {
			puts("0");
			return 0;
		}
	}
	int c = 0;
	for (i = 1; i <= m; i++) {
		c++;
		if (i==m || w[i] != w[i + 1]) {
			P[++cnt] = { w[i],c };
			c = 0;
			if (cnt > 1005) {
				puts("0");
				return 0;
			}
		}
	}
	for (i = 1; i <= cnt; i++) {
		if (!LL[P[i].a])LL[P[i].a] = i;
		RR[P[i].a] = i;
	}
	for (i = 1; i <= cnt + 1; i++)DD[i][i-1] = D[i][i - 1] = 1;
	for (int l = 1; l <= cnt; l++) {
		for (i = 1; i <= cnt - l + 1; i++) {
			int b = i, e = i + l - 1;
			if (l == 1) {
				int x = P[b].a;
				if(LL[x] == b && RR[x] == b)DD[b][e] = D[b][e] = 1;
				continue;
			}
			int Mn = 1e9, pv = -1, ck = 0;
			for (j = b; j <= e; j++) {
				if (Mn > P[j].a)Mn = P[j].a, pv = j;
				if (LL[P[j].a]<b || RR[P[j].a]>e)ck = 1;
			}
			if (ck)continue;
			int x = P[pv].a;
			int prev = b - 1;
			long long z = 1;
			for (j = b; j <= e; j++) {
				if (P[j].a == x) {
					z = z * D[prev + 1][j - 1] % Mod;
					prev = j;
				}
			}
			z = z * D[prev + 1][e] % Mod;
			DD[b][e] = (DD[b][e] + z) % Mod;
			D[b][e] = DD[b][e];
			for (j = b; j < e; j++) {
				D[b][e] = (D[b][e] + DD[b][j] * D[j + 1][e]) % Mod;
			}
		}
	}
	printf("%lld\n", D[1][cnt]);

}