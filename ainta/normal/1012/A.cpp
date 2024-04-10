#include<cstdio>
#include<algorithm>
#define N_ 201000
using namespace std;
int w[N_], n;
long long res = 1e18;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < 2 * n; i++)scanf("%d", &w[i]);
	sort(w, w + 2 * n);
	for (i = 0; i <= n; i++) {
		int d = w[i + n - 1] - w[i];
		long long t;
		if (i == 0)t = w[2 * n - 1] - w[n];
		else if (i == n)t = w[n - 1] - w[0];
		else t = w[2 * n - 1] - w[0];
		res = min(res, t*d);
	}
	printf("%lld\n", res);
}