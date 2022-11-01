#include <cstdio>
int main() {
	int c, v, M, a, l, i=0, t=0;
	scanf("%d %d %d %d %d", &c, &v, &M, &a, &l);
	while (1) {
		t += v;
		i++;
		if (t >= c) break;
		t -= l;
		v += a;
		if (v > M) v = M;
	}
	printf("%d", i);
}