#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define N_ 501000
using namespace std;
int n, w[(1 << 25) + 1], S[(1 << 25) + 1], res;
int Sum(int b, int e) {
	return S[e + 1] - S[b];
}
void Do(int K) {
	int i;
	for (i = 0; i < (1 << K); i++) {
		S[i + 1] = S[i] + w[i];
	}
	long long s = 0;
	int M = 1 << (K - 1);
	for (i = 0; i < M; i++) {
		s+=1ll*Sum(M - i, M + M - i - 1) * w[i];
	}
	for (i = M; i < M+M; i++) {
		int t = M + M - i;
		s+= 1ll * (Sum(0, t - 1) + Sum(t + M, M + M - 1))*w[i];
	}
	for (i = 0; i < M + M; i++) {
		if (((i + i) >> (K - 1)) & 1)s -= w[i];
	}
	s /= 2;
	if (s & 1)res |= (1 << (K - 1));
	for (i = M; i < M + M; i++)w[i - M] += w[i];
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		w[a]++;
	}
	for (i = 25; i >= 1; i--) {
		Do(i);
	}
	printf("%d\n", res);
}