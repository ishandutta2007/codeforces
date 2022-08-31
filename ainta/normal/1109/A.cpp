#include<cstdio>
#include<algorithm>
#define N_ 301000
using namespace std;
int n, w[N_], C[1<<21][2], s;
long long res;
int main() {
	int i;
	scanf("%d", &n);
	s = 0;
	C[s][0] = 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		s ^= w[i];
		res += C[s][i % 2];
		C[s][i % 2]++;
	}
	printf("%lld\n", res);
}