#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long w[201000], S, A;
void Solve() {
	int i;
	scanf("%d", &n);
	S = A = 0;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		S += w[i];
		A ^= w[i];
	}
	printf("2\n%lld %lld\n", A, S + A);
}
int main() {
	int TC, t;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}