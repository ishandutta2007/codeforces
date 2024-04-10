#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long w[201000], A[201000], M[201000];
void Solve() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		A[i] = w[i] + M[i - 1];
		M[i] = max(M[i - 1], A[i]);
		printf("%lld ", A[i]);
	}
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}