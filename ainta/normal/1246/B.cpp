#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>P[101000];
int n, K, w[101000], U, C[101000];
long long res;
int main() {
	int i, j;
	scanf("%d%d", &n, &K);
	for (i = 2; i <= 100000; i++) {
		if (!P[i].empty())continue;
		for (j = i; j <= 100000; j += i) {
			P[j].push_back(i);
		}
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		int a = w[i];
		long long z = 1, z2 = 1;
		for (auto &t : P[a]) {

			int tp = a, c = 0;
			while (tp%t == 0) {
				tp /= t;
				c++;
			}
			c %= K;
			for (j = 0; j < c; j++) {
				z2 = z2 * t;
			}
			for (j = 0; j < (K - c) % K; j++) {
				if (z > 1e6)break;
				z = z * t;
			}
		}
		res += C[z2];
		if (z <= 100000)C[z]++;
	}
	printf("%lld\n", res);
}