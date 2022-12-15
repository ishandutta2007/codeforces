#include <stdio.h>
#include <algorithm>
#include <vector>

int n, m, k;
int x, s;
int a[200000], b[200000], c[200000], d[200000];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d", &x, &s);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	for (int i = 0; i < k; i++) scanf("%d", &c[i]);
	for (int i = 0; i < k; i++) scanf("%d", &d[i]);

	long long min = (1ll) << 63 - 1, sum;
	for (int i = 0; i < m; i++) {
		if (a[i] >= x) continue;
		if (b[i] > s) continue;

		int num = s - b[i], time = a[i];
		int idx = std::upper_bound(d, d + k, num) - d;
		if (idx == 0) {
			sum = (long long)n * time;
			if (sum < min) min = sum;
		}
		else {
			idx--;
			int make = n - c[idx];
			sum = (long long)make * time;
			if (sum < min) min = sum;
		}
	}
	int num = s, time = x;
	int idx = std::upper_bound(d, d + k, num) - d;
	if (idx == 0) {
		sum = (long long)n * time;
		if (sum < min) min = sum;
	}
	else {
		idx--;
		int make = n - c[idx];
		sum = (long long)make * time;
		if (sum < min) min = sum;
	}

	printf("%I64d\n", min);

	return 0;
}