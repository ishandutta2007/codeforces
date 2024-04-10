#include <cstdio>
int a[4], sum, t;
int main(){
	for (register int i = 0; i < 4; ++i) scanf("%d", a + i), sum += a[i];
	for (register int p = 0; p < (1 << 4); ++p){
		t = 0;
		for (register int i = 0; i < 4; ++i)
			if (p >> i & 1) t += a[i];
		if (t == sum - t) return puts("YES"), 0;
	}
	puts("NO");
}