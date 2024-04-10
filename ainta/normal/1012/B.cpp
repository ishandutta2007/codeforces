#include<cstdio>
#include<algorithm>
#define N_ 401000
using namespace std;
int UF[N_], v[N_];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
int n, m, K;
void Merge(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b)UF[a] = b;
}
int main() {
	int i, x, y;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 1; i <= n + m; i++)UF[i] = i;
	for (i = 0; i < K; i++) {
		scanf("%d%d", &x, &y);
		Merge(x, n + y);
	}
	int res = 0;
	for (i = 1; i <= n+m; i++) {
		if (!v[Find(i)]) {
			v[Find(i)] = 1;
			res++;
		}
	}
	printf("%d\n", res - 1);
}