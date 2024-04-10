#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000], A[101000], B[101000], BIT[101000];
void Add(int a, int b) {
	while (a <= n) {
		BIT[a] += b;
		a += (a&-a);
	}
}
int Sum(int a) {
	int r = 0;
	while (a) {
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &A[i]);
	for (i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
		w[B[i]] = i;
	}
	int res = 0;
	for (i = 1; i <= n; i++) {
		if (Sum(n) - Sum(w[A[i]])) {
			res++;
		}
		Add(w[A[i]], 1);
	}
	printf("%d\n", res);
}