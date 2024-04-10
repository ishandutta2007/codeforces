#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n;
vector<long long>V;
vector<long long>P;
long long D[10100][60], S[60], Inv[70], Mod = 1000000007;
int K;
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = a*r%Mod;
		a = a*a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int i, j, k;
	for (i = 1; i <= 60; i++)Inv[i] = Pow(i, Mod - 2);
	scanf("%lld", &n);
	for (i = 1; 1ll*i*i <= n; i++) {
		if (n%i == 0) {
			V.push_back(i);
			if (n / i != i)V.push_back(n / i);
		}
	}
	sort(V.begin(), V.end());
	int m = V.size();
	for (i = 0; i < m; i++) {
		if (V[i] == 1)continue;
		int ck = 0;
		for (auto &t : P) {
			if (V[i] % t == 0) {
				ck = 1;
				break;
			}
		}
		if (!ck) {
			P.push_back(V[i]);
		}
	}
	vector<int>C;
	long long x = n;
	for (auto &t : P) {
		int c = 0;
		while (x%t == 0) {
			x /= t;
			c++;
		}
		C.push_back(c);
	}
	scanf("%d", &K);
	long long res = 1;
	for (i = 0; i < P.size(); i++) {
		int M = C[i];
		for (j = 0; j <= K; j++)for (k = 0; k <= M; k++)D[j][k] = 0;
		D[0][M] = 1;
		for (j = 0; j < K; j++) {
			for (k = 0; k <= M; k++)S[k] = 0;
			for (k = 0; k <= M; k++) {
				S[0] += D[j][k] * Inv[k + 1]%Mod;
				S[k + 1] += Mod - D[j][k] * Inv[k + 1] % Mod;
			}
			for (k = 1; k <= M; k++)S[k] += S[k - 1];
			for (k = 0; k <= M; k++)D[j + 1][k] = S[k] % Mod;
		}
		long long t = 1, ss = 0;
		for (j = 0; j <= M; j++) {
			ss = (ss + (t%Mod)*D[K][j]) % Mod;
			if (j == M)break;
			t *= P[i];
		}
		res = res*ss%Mod;
	}
	printf("%lld\n",res);
	return 0;
}