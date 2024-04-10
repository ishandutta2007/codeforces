#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 524288
using namespace std;
int n, m, K;
int X[401000], CX;
struct point {
	int b, e;
}A[201000], B[201000];
vector<int>EA[401000], EB[401000];
long long Mod = 1000000007;
struct Tree {
	long long S[SZ+SZ], K[SZ+SZ];
	void DelNode(int nd) {
		S[nd] = 0;
		K[nd] = 1;
	}
	void Spread(int nd) {
		if (K[nd]) {
			DelNode(nd * 2);
			DelNode(nd * 2 + 1);
		}
		K[nd] = 0;
	}
	void UDT(int nd) {
		S[nd] = (S[nd * 2] + S[nd * 2 + 1])%Mod;
	}
	void Del(int nd, int b, int e, int s, int l) {
		if (s > l)return;
		if (b == s && e == l) {
			DelNode(nd);
			return;
		}
		int m = (b + e) >> 1;
		Spread(nd);
		if(s<=m)Del(nd * 2, b, m, s, min(m, l));
		if(l>m)Del(nd * 2 + 1, m + 1, e, max(m + 1, s), l);
		UDT(nd);
	}
	void Put(int nd, int b, int e, int x, long long g) {
		if (b == e) {
			S[nd] = g%Mod;
			return;
		}
		int m = (b + e) >> 1;
		Spread(nd);
		if (x <= m)Put(nd*2, b, m, x, g);
		else Put(nd * 2 + 1, m + 1, e, x, g);
		UDT(nd);
	}
	long long Sum(int nd, int b, int e, int s, int l) {
		if (b == s&&e == l)return S[nd];
		int m = (b + e) >> 1;
		Spread(nd);
		long long r = 0;
		if (s <= m)r += Sum(nd * 2, b, m, s, min(m, l));
		if (l>m)r += Sum(nd * 2 + 1, m + 1, e, max(m + 1, s), l);
		return r;
	}
}TA, TB;
long long SS = 1;
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r*a%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int i, j;
	scanf("%d%d%d", &K, &n, &m);
	X[CX++] = 0, X[CX++] = K;
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &A[i].b, &A[i].e);
		A[i].b--;
		X[CX++] = A[i].b;
		X[CX++] = A[i].e;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &B[i].b, &B[i].e);
		B[i].b--;
		X[CX++] = B[i].b;
		X[CX++] = B[i].e;
	}
	sort(X, X + CX);
	CX = unique(X, X + CX) - X;
	for (i = 1; i <= n; i++) {
		A[i].b = lower_bound(X, X + CX, A[i].b) - X;
		A[i].e = lower_bound(X, X + CX, A[i].e) - X;
		EA[A[i].e].push_back(A[i].b);
	}
	for (i = 1; i <= m; i++) {
		B[i].b = lower_bound(X, X + CX, B[i].b) - X;
		B[i].e = lower_bound(X, X + CX, B[i].e) - X;
		EB[B[i].e].push_back(B[i].b);
	}
	for (i = 1; i < CX; i++) {
		int x = -1;
		for (auto &t : EA[i]) {
			x = max(x, t);
		}
		long long OTA = TA.S[1], OTB = TB.S[1];
		long long s2 = (SS + TA.S[1] + TB.S[1])%Mod;
		TA.Del(1, 0, SZ - 1, 0, x);
		if (x != i - 1) {
			TA.Put(1, 0, SZ - 1, i - 1, OTB + SS);
		}
		x = -1;
		for (auto &t : EB[i]) {
			x = max(x, t);
		}
		TB.Del(1, 0, SZ - 1, 0, x);
		if (x != i - 1) {
			TB.Put(1, 0, SZ - 1, i - 1, OTA + SS);
		}
	
		SS = s2 * (Pow(2, X[i] - X[i - 1]) + Mod - 2) % Mod;
	}
	printf("%lld\n", (SS+TA.S[1]+TB.S[1])%Mod);
}