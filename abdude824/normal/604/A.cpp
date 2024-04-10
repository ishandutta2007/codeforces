#include <stdio.h>
#include <stdlib.h>

int main() {
	int m[5];
	int w[5];
	int i, hs, hu, v, s;

	for(i = 0; i < 5; i++) {
		scanf("%d", &m[i]);
	}
	for(i = 0; i < 5; i++) {
		scanf("%d", &w[i]);
	}
	scanf("%d%d", &hs, &hu);
	s = 0;
	for(i = 0; i < 5; i++) {
		v = (250 - m[i]) * 2 * (i+1) - 50 * w[i];
		if(v < 150 * (i+1)) v = 150 * (i+1);
		s += v;
	}
	s += 100 * hs - 50 * hu;
	printf("%d\n", s);

	return 0;
}