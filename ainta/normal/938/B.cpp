#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000], res = 1e9;
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	w[0] = 1, w[n + 1] = 1000000;
	for (i = 0; i <= n; i++) {
		res = min(res, max(w[i] - w[0], w[n + 1] - w[i + 1]));
	}
	printf("%d\n", res);
}