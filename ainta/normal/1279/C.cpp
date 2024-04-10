#include<cstdio>
#include<algorithm>
using namespace std;
int n, A[101000], B[101000], m;
void Solve() {
	int i, a;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		A[a] = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &a);
		B[i] = A[a];
	}
	int Mx = 0;
	long long res = 0;
	for (i = 1; i <= m; i++) {
		if (Mx < B[i]) {
			res += (B[i] - i)*2+1;
			Mx = B[i];
		}
		else res++;
	}
	printf("%lld\n", res );
}
int main() {
	int a, b, c, TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}