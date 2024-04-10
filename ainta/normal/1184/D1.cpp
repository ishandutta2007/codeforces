#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, m, Q;
int main() {
	int i, ck, a;
	scanf("%d%d%d%d", &n, &K, &m, &Q);
	while (Q--) {
		scanf("%d%d", &ck, &a);
		if (ck == 0) {
			if (a < K) {
				K -= a;
				n -= a;
			}
			else {
				n = a;
			}
		}
		else {
			if (a <= K)K++;
			n++;
		}
		printf("%d %d\n", n, K);
	}
}