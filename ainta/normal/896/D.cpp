#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 131072
using namespace std;
int Mod, Res[101000], n, L, R, CC[101000];
vector<int>P[101000], U[101000];
int IT[SZ + SZ], C[101000];
void Put(int a, int b) {
	a += SZ;
	IT[a] = b;
	while (a != 1) {
		a >>= 1;
		IT[a] = 1ll * IT[a + a] * IT[a + a + 1] % Mod;
	}
}
void Ins(int a, int b) {
	int i;
	for (i = 0; i < P[a].size(); i++) {
		int x = P[a][i];
		C[x] += b;
		while (C[x] >= U[x].size()) {
			U[x].push_back(1ll * U[x].back() * x % Mod);
		}
	}
	for (i = 0; i < P[a].size(); i++) {
		Put(P[a][i], U[P[a][i]][C[P[a][i]]]);
	}
}
int main() {
	int i, j;
	scanf("%d%d%d%d", &n, &Mod, &L, &R);
	for (i = 1; i < SZ + SZ; i++)IT[i] = 1;
	for (i = 1; i <= n; i++)U[i].push_back(1);
	for (i = 2; i <= n; i++) {
		if (!P[i].empty())continue;
		for (j = i; j <= n; j+=i) {
			int t = j;
			while (t%i == 0) {
				t /= i;
				P[j].push_back(i);
			}
		}
	}
	int p1 = 0, p2 = L - 1, p3 = L - 1;
	for (i = L; i <= n; i++) {
		int t = (i - L) / 2;
		int b = i - t + 1, e = i;
		while (p3 < e) {
			p3++;
			Ins(p3, 1);
		}
		while (p2+1 < b) {
			p2++;
			Ins(p2, -1);
		}
		while (p1 < t) {
			p1++;
			Ins(p1, -1);
		}
		Res[i] = IT[1];
	}

	for (i = 1; i < SZ + SZ; i++)IT[i] = 1;
	for (i = 1; i <= n; i++)C[i] = 0;

p1 = 0, p2 = R - 1, p3 = R - 1;

	for (i = R+1; i <= n; i++) {
		int t = (i - R + 1) / 2 - 1;
		int b = i - t + 1, e = i;
		while (p3 < e) {
			p3++;
			Ins(p3, 1);
		}
		while (p2 + 1 < b) {
			p2++;
			Ins(p2, -1);
		}
		while (p1 < t) {
			p1++;
			Ins(p1, -1);
		}
		Res[i] = ((long long)Res[i] + Mod - IT[1]) % Mod;
	}
	

	for (i = 1; i < SZ + SZ; i++)IT[i] = 1;
	for (i = 1; i <= n; i++)C[i] = 0;


	CC[0] = 1;
	for (i = 1; i <= n; i++) {
		Ins(n - i + 1, 1);
		Ins(i, -1);
		CC[i] = IT[1];
	}

	int rr = 0;
	for (i = 0; i <= n; i++) {
		rr = (rr + 1ll * Res[i] * CC[n - i]) % Mod;
	}
	printf("%d\n", rr);

}