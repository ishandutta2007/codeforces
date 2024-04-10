#include <cstdio>
#include <algorithm>
using namespace std;
int MAX = 524288;
int fil[524288][20] = { 0 }, a[300000], q[300000];
int main() {
	int n, m, i, tmp, j, tmp2, k, p[20];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (i = 0; i < n; i++) {
		if (i==0 || a[i] != a[i - 1]) {
			tmp = a[i];
			for (j = 0; j < 20; j++) {
				fil[tmp][j]++;
				tmp /= 2;
			}
		}
	}
	tmp = 1;
	for (j = 0; j < 20; j++) {
		for (i = 0; i < MAX; i++) {
			if (fil[i][j] < tmp) fil[i][j] = 0;
		}
		tmp *= 2;
	}
	
	for (i = 0; i < m; i++) {
		scanf("%d", &tmp);
		if (i == 0) q[0] = tmp;
		else q[i] = q[i - 1] ^ tmp;
	}
	for (i = 0; i < m; i++) {
		tmp = q[i];
		for (j = 0; j < 20; j++) {
			p[j] = tmp % 2;
			tmp /= 2;
		}
		tmp = 0;
		for (j = 19; j >= 0; j--) {
			if (fil[tmp * 2 + p[j]][j]) tmp = tmp * 2 + (!p[j]);
			else tmp = tmp * 2 + p[j];
		}
		printf("%d\n", tmp^q[i]);
	}
}