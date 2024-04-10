#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int w[101000], P[101000], cnt;
long long S, res = 1e18;
void Solve(int K) {
	int i, j;
	long long s = 0;
	for (i = 0; i < cnt; i+=K) {
		int t = P[(i + (i + K - 1)) / 2];
		for (j = i; j < i + K; j++) {
			s+=abs(t - P[j]);
		}
	}
	res = min(res, s);
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (w[i])P[cnt++] = i;
		S += w[i];
	}
	for (i = 1; i <= S; i++) {
		if (S%i == 0 && i>1) {
			Solve(i);
		}
	}
	if (res > 8e17)res = -1;
	printf("%lld\n", res);
}