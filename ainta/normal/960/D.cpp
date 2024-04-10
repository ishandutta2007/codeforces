#include<cstdio>
#include<algorithm>
using namespace std;
long long P[64], po[63];
int Q;
int Level(long long a) {
	int i;
	for (i = 0; i <= 60; i++) {
		if (po[i] <= a && a < po[i + 1])break;
	}
	return i;
}
void Add(int dep, long long a) {
	long long c = (1ll << dep);
	if (a < 0) {
		a += ((-a) / c + 1)*c;
	}
	P[dep] = (P[dep] + a) % c;
}
long long Up(long long x) {
	if (x == 1)return 0;
	int t = Level(x);
	x += P[t];
	while (x < po[t])x += po[t];
	while (x >= po[t + 1])x -= po[t];
	x = (x / 2) - P[t - 1];
	while (x < po[t - 1])x += po[t - 1];
	while (x >= po[t])x -= po[t - 1];
	return x;
}
int main() {
	int i, ck;
	po[0] = 1;
	for (i = 0; i <= 61; i++)po[i + 1] = po[i] * 2;
	long long x, k;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%lld", &ck, &x);

		if (ck == 1) {
			scanf("%lld", &k);
			Add(Level(x), k);
		}
		if (ck == 2) {
			scanf("%lld", &k);
			long long s = (1ll << Level(x));
			if (k < 0) {
				k += ((-k) / s + 1)*s;
			}
			k %= s;
			for (i = Level(x); i <= 61; i++) {
				Add(i, k<<(i-Level(x)));
			}
		}
		if (ck == 3) {
			while (x) {
				printf("%lld ", x);
				x = Up(x);
			}
			printf("\n");
		}
	}
}