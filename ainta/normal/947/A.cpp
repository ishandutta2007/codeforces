#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, v[1010000], M[1010000];
int main() {
	int i, j;
	for (i = 2; i <= 1000000; i++) {
		if (v[i])continue;
		for (j = i; j <= 1000000; j+=i) {
			v[j] = 1;
			M[j] = i;
		}
	}
	scanf("%d", &n);
	int t = M[n];
	int res = n - t + 1;
	for (i = n - t + 1; i <= n; i++) {
		if (M[i] == i)continue;
		res = min(res, i - M[i] + 1);
	}
	printf("%d\n", res);
}