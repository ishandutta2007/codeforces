#include<cstdio>
#include<algorithm>
using namespace std;
char p[501000], q[501000], r[501000];
int n, m, C[2], oto[501000];
int main() {
	scanf("%s", q);
	scanf("%s", p);
	int i;
	for (i = 0; q[i]; i++) {
		C[q[i] - '0']++;
	}
	m = i;
	oto[0] = -1;
	for (i = 0; p[i]; i++) {
		int t = oto[i];
		while (t != -1 && p[i] != p[t])t = oto[t];
		oto[i + 1] = t + 1;
	}
	n = i;
	for (i = 0; i < n; i++) {
		C[p[i] - '0']--;
		r[i] = p[i];
	}
	if (C[0] < 0 || C[1] < 0) {
		printf("%s\n", q);
		return 0;
	}
	int pv = n;
	while (1) {
		int ck = 0;
		for (i = 0; i < n - oto[n]; i++) {
			if (!C[p[oto[n] + i] - '0']) {
				ck = 1;
				break;
			}
			r[pv++] = p[oto[n] + i];
			C[p[oto[n] + i] - '0']--;
		}
		if (ck)break;
	}
	for (i = 0; i < C[0]; i++)r[pv++] = '0';
	for (i = 0; i < C[1]; i++)r[pv++] = '1';
	printf("%s\n", r);
}