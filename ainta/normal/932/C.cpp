#include<cstdio>
#include<algorithm>
using namespace std;
int n, A, B;
void Cycle(int b, int e) {
	int i;
	for (i = b; i < e; i++)printf("%d ", i + 1);
	printf("%d ", b);
}
void Do(int a, int b) {
	int i, pv = 0;
	for (i = 0; i < a; i++) {
		Cycle(pv + 1, pv + A);
		pv += A;
	}
	for (i = 0; i < b; i++) {
		Cycle(pv + 1, pv + B);
		pv += B;
	}
}
int main() {
	int i;
	scanf("%d%d%d", &n,&A,&B);
	for (i = 0; i*A <= n; i++) {
		if ((n - i*A) % B)continue;
		Do(i, (n - i*A) / B);
		return 0;
	}
	printf("-1\n");
}