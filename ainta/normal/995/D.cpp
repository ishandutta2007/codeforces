#include<cstdio>
#include<algorithm>
using namespace std;
int w[1 << 18], n, Q;
long long s;
int main() {
	int i, a, b;
	scanf("%d%d", &n,&Q);
	for (i = 0; i < (1 << n); i++) {
		scanf("%d", &w[i]);
		s += w[i];
	}
	printf("%f\n", 1.0*s / (1 << n));
	for (i = 1; i <= Q; i++) {
		scanf("%d%d", &a, &b);
		s -= w[a];
		s += b;
		w[a] = b;
		printf("%f\n", 1.0*s / (1 << n));
	}
}