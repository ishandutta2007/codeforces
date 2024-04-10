#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long S[301000], w[301000], X, Res;
long long D[301000][3];
int main() {
	int i, a;
	scanf("%d%lld", &n, &X);
	long long Mn = 0, Mx = 0, R1 = 0, R2 = 0;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		S[i] = S[i - 1] + w[i];
	}
	for (i = 1; i <= n; i++) {
		D[i][0] = max(D[i - 1][0] + w[i], w[i]);
		D[i][1] = max(D[i - 1][0] + w[i] * X, max(D[i - 1][1] + w[i] * X, w[i]*X));
		D[i][2] = max(D[i - 1][1] + w[i], D[i - 1][2] + w[i]);
		Res = max(Res, max(max(D[i][0], D[i][1]), D[i][2]));
	}
	printf("%lld\n", Res);
}